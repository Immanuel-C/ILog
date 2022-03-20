#include "ILog.h"

int main() {
    I_DEBUG_LOG_INFO("Some Info %u", 100ULL);
    I_DEBUG_LOG_TRACE("Tracey things happened %d", 1000);
    I_DEBUG_LOG_WARNING("Something happened %d", -199);
    I_DEBUG_LOG_ERROR("Some Error Happened %zu", 10);
    I_DEBUG_LOG_FATAL_ERROR("Some Fatal Error Happened %s %ull %d", "Error", 50ULL, 600);

    I_LOG_INFO("Some Info %u", 100ULL);
    I_LOG_TRACE("Tracey things happened %d", 100);
    I_LOG_WARNING("Something happened %d", -199);
    I_LOG_ERROR("Some Error Happened %zu", 10);
    I_LOG_FATAL_ERROR("Some Fatal Error Happened %s %ull %d", "Error", 50ULL, 600);

    I_ASSERT_ERROR(0, "Assert Error");
    I_ASSERT_FATAL_ERROR(0, "Assert Error");

    return 0;
}