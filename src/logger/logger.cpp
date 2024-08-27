#include "logging.h"

#include <mutex>

static std::mutex log_mutex = {};
static FILE *log_file = nullptr;

#define MIDE_LOG_TO_FILE 1

static bool is_initialized = false;

namespace mide
{
bool init()
{
	const std::size_t max_logfiles = 9999;
	const char *mide_logfile_root = "mide_log_";
	const std::size_t mide_logfile_root_len =
		strnlen(mide_logfile_root, 100);

	char char_buffer[64];
	std::size_t char_buffer_size = 64;

	for (std::size_t i = 0; i < max_logfiles; i++) {
		snprintf(char_buffer, char_buffer_size, "mide_log_%zd.txt", i);

		if (std::filesystem::exists(char_buffer)) {
			continue;
		}

		log_file = fopen(char_buffer, "w");
		if (log_file != nullptr) {
			printf("Log file: %s\n", char_buffer);

			auto tt = time(nullptr);
			auto *ti = localtime(&tt);
			std::cerr << "Current date: " << std::put_time(ti, "%c")
				  << std::endl;
			break;
		}
	}

	if (log_file == nullptr) {
		return false;
	}

	return true;
}

void log(LogLevel log_level, const char *fmt, ...)
{
	if (APP_LOG_LEVEL > log_level) {
		return;
	}

	if (!is_initialized) {
		if (!init()) {
			fprintf(stderr, "ERROR: failed to initialize logger\n");
			return;
		} else {
			is_initialized = true;
		}
	}

	log_mutex.lock();

	time_t ltime;
	ltime = time(NULL);
	const char *timestamp_string = asctime(localtime(&ltime));

	auto tt = time(nullptr);
	auto *ti = localtime(&tt);
	std::stringstream sstream;

	sstream << std::put_time(ti, "%T");

	switch (log_level) {
	case LogLevel::Debug:
		sstream << ": debug: ";
		break;
	case LogLevel::Info:
		sstream << ": info: ";
		break;
	case LogLevel::Warn:
		sstream << ": warn: ";
		break;
	case LogLevel::Err:
		sstream << ": error: ";
		break;
	default:
		assert(false);
	}

	va_list args;

#ifdef MIDE_LOG_TO_CONSOLE
	fprintf(stderr, "%s", sstream.str().c_str());
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
#endif

#ifndef MIDE_LOG_TO_FILE
	fprintf(log_file, "%s", sstream.str().c_str());
	va_start(args, fmt);
	vfprintf(log_file, fmt, args);
	va_end(args);
	fflush(log_file);
#endif

	log_mutex.unlock();
}

} // namespace mide