/*
 * Auto-added header
 * File: logger/logger.h
 * Author: camradeling
 * Email: camradeling@gmail.com
 * 2025
 */
#pragma once
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

// ==============================
// ANSI color codes for log levels
// ==============================
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_GRAY    "\x1b[90m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// ==============================
// Log levels
// ==============================
#define LOG_LEVEL_ERROR 0
#define LOG_LEVEL_WARN  1
#define LOG_LEVEL_INFO  2
#define LOG_LEVEL_DEBUG 3

#ifndef LOGGER_DEFAULT_LEVEL
#define LOGGER_DEFAULT_LEVEL LOG_LEVEL_INFO
#endif

// ==============================
// Internal logging macro
// ==============================
// This prints timestamp + level + message with colors
#define LOG_PRINT(level, color, label, fmt, ...) do {                     \
    if (level <= LOGGER_DEFAULT_LEVEL) {                                  \
        struct timeval tv;                                                \
        gettimeofday(&tv, NULL);                                          \
        struct tm *tm_info = localtime(&tv.tv_sec);                       \
        char timebuf[64];                                                 \
        strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm_info); \
        fprintf(stderr, "%s.%03ld [%s%s%s] " fmt "\n",                    \
                timebuf, tv.tv_usec/1000, color, label, ANSI_COLOR_RESET, \
                ##__VA_ARGS__);                                           \
    }                                                                     \
} while(0)

// ==============================
// User-facing macros
// ==============================
#define LOG_ERROR(fmt, ...) LOG_PRINT(LOG_LEVEL_ERROR, ANSI_COLOR_RED,   "ERROR", fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...)  LOG_PRINT(LOG_LEVEL_WARN,  ANSI_COLOR_YELLOW,"WARN ", fmt, ##__VA_ARGS__)
#define LOG_INFO(fmt, ...)  LOG_PRINT(LOG_LEVEL_INFO,  ANSI_COLOR_GREEN, "INFO ", fmt, ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...) LOG_PRINT(LOG_LEVEL_DEBUG, ANSI_COLOR_GRAY,  "DEBUG", fmt, ##__VA_ARGS__)
