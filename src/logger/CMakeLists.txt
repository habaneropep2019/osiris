include_directories(${KDELIBS_SOURCE_DIR}/logger)

set(LOGGER_SRCS logger.cpp)

add_library(mlogger SHARED ${LOGGER_SRCS})
install(TARGETS mlogger LIBRARY DESTINATION ${KDE1_LIBRARIES})

install(FILES logger.h DESTINATION ${KDE1_INCLUDES})

