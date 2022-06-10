#include <chrono>
#include <iostream>
#include <thread>

#include <stdio.h>

#if ANDROID

#include <android/log.h>

static const char* kTAG = "Test APP";

#define TRACE(...) ((void)__android_log_print(ANDROID_LOG_VERBOSE, kTAG, __VA_ARGS__))
#define DEBUG(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, kTAG, __VA_ARGS__))
#define INFO(...) ((void)__android_log_print(ANDROID_LOG_INFO, kTAG, __VA_ARGS__))
#define WARN(...) ((void)__android_log_print(ANDROID_LOG_WARN, kTAG, __VA_ARGS__))
#define ERR(...) ((void)__android_log_print(ANDROID_LOG_ERROR, kTAG, __VA_ARGS__))

#else

#define TRACE(...) (printf(__VA_ARGS__))
#define DEBUG(...) (printf(__VA_ARGS__))
#define INFO(...) (printf(__VA_ARGS__))
#define WARN(...) (printf(__VA_ARGS__))
#define ERR(...) (printf(__VA_ARGS__))

#endif

int main(int argc, char* argv[]) {

    INFO("Test app started");

    while (1) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        INFO("Tick...");
    }

}