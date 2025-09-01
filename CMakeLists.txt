cmake_minimum_required(VERSION 3.10)
project(logger)

# =========================
# Build-time configuration
# =========================

# Allow user to override default log level at CMake configure step
# Example: cmake -DLOGGER_DEFAULT_LEVEL=2 ..
# 0 = ERROR, 1 = WARN, 2 = INFO, 3 = DEBUG
set(LOGGER_DEFAULT_LEVEL 2 CACHE STRING "Default log level (0=ERROR, 1=WARN, 2=INFO, 3=DEBUG)")

# Pass the log level as a preprocessor macro
# globally for all targets
add_library(logger_config INTERFACE)
target_compile_definitions(logger_config 
    INTERFACE 
        LOGGER_DEFAULT_LEVEL=${LOGGER_DEFAULT_LEVEL})

target_include_directories(logger_config
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# =========================
# Optional test program
# =========================
option(BUILD_LOGGER_TEST "Build logger test program" ON)

if (BUILD_LOGGER_TEST)
    add_executable(logger_test
        logger_test.c
    )
    target_link_libraries(logger_test PRIVATE logger_config)
endif()
