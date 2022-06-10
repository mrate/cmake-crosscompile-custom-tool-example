#include <chrono>
#include <iostream>
#include <thread>

#include <stdio.h>

#if ANDROID

#include <android/log.h>
#include <android/sharedmem.h>

#include <sys/mman.h>

#include <EGL/egl.h>
#include <GLES3/gl31.h>

static const char* kTAG = "SomniumCompositor";

#define SOM_TRACE(...) ((void)__android_log_print(ANDROID_LOG_VERBOSE, kTAG, __VA_ARGS__))
#define SOM_DEBUG(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, kTAG, __VA_ARGS__))
#define SOM_INFO(...) ((void)__android_log_print(ANDROID_LOG_INFO, kTAG, __VA_ARGS__))
#define SOM_WARN(...) ((void)__android_log_print(ANDROID_LOG_WARN, kTAG, __VA_ARGS__))
#define SOM_ERR(...) ((void)__android_log_print(ANDROID_LOG_ERROR, kTAG, __VA_ARGS__))

#else

#define SOM_TRACE(...) (printf(__VA_ARGS__))
#define SOM_DEBUG(...) (printf(__VA_ARGS__))
#define SOM_INFO(...) (printf(__VA_ARGS__))
#define SOM_WARN(...) (printf(__VA_ARGS__))
#define SOM_ERR(...) (printf(__VA_ARGS__))

#endif

int main(int argc, char* argv[]) {

    #if ANDROID
    SOM_INFO("Somnium Compositor started");

    auto fd{ ASharedMemory_create("somnium_compositor", 1024) };
    const auto memSize{ ASharedMemory_getSize(fd) };
    auto memory{ static_cast<char*>(mmap(nullptr, memSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) };
#endif

    while (1) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        SOM_INFO("Tick...");
    }

}