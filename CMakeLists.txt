cmake_minimum_required(VERSION 3.10)
project(logger)
# Create a static library called "logger" from logger.cpp
add_library(logger STATIC
    logger.cpp
)

# Expose the current directory so that "logger.h" can be included
# with #include "logger.h" from other parts of the project
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
