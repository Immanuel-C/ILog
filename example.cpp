#include "IC_Logger.h"

int main() {
    IC_DEBUG_LOG_INFO("Some Info %ull", 100ULL);
    IC_DEBUG_LOG_TRACE("Tracey things happened %d", 1000);
    IC_DEBUG_LOG_WARNING("Something happened %d", -199);
    IC_DEBUG_LOG_ERROR("Some Error Happened %zu", 10);
    IC_DEBUG_LOG_FATAL_ERROR("Some Fatal Error Happened %s %ull %d", "Error", 50ULL, 600);

    IC_LOG_INFO("Some Info %ull", 100ULL);
    IC_LOG_TRACE("Tracey things happened %d", 1000);
    IC_LOG_WARNING("Something happened %d", -199);
    IC_LOG_ERROR("Some Error Happened %zu", 10);
    IC_LOG_FATAL_ERROR("Some Fatal Error Happened %s %ull %d", "Error", 50ULL, 600);

    return 0;
}