#include "logger.h"

int main() {
    LOG_ERROR("This is an ERROR message");
    LOG_WARN("This is a WARN message");
    LOG_INFO("This is an INFO message");
    LOG_DEBUG("This is a DEBUG message");
    return 0;
}
