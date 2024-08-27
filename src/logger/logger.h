#pragma once

#include <cstring>
#include <cwchar>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <thread>
#include <cassert>
#include <stddef.h>
#include <iomanip>
#include <sstream>
#include <time.h>
#include <filesystem>
#include <stdarg.h>

#ifndef APP_LOG_LEVEL
# define APP_LOG_LEVEL LogLevel::Info
#endif

namespace mide
{
enum LogLevel {
	Debug,
	Info,
	Warn,
	Err,
	None,
};

void log(LogLevel log_level, const char *fmt, ...);
} // namespace mide