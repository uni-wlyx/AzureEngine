#ifndef CORE_H
#define CORE_H

#ifdef AZUR_PLATFORM_WINDOWS
    #ifdef AZUR_EXPORT
        #define AZUR_API __declspec(dllexport)
    #else
        #define AZUR_API __declspec(dllimport)
    #endif
#endif

#ifdef AZ_ENABLE_ASSERTS
    #define AZ_ASSERT(x,...) {if(!(x)){AZ_ERROR("Assertion Failed:{0)",__VA_ARGS__);__debugbreak();}}
    #define AZ_CORE_ASSERT(x,...) {if(!(x)){AZ_CORE_ERROR("Assertion Failed:{0)",__VA_ARGS__);__debugbreak();}}
#else
    #define AZ_ASSERT(x,...)
    #define AZ_CORE_ASSERT(x,...)
#endif

#endif //CORE_H
