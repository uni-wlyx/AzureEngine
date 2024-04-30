#ifndef CORE_H
#define CORE_H

#ifdef AZUR_PLATFORM_WINDOWS
    #ifdef AZUR_EXPORT
        #define AZUR_API __declspec(dllexport)
    #else
        #define AZUR_API __declspec(dllimport)
    #endif
#endif

#endif //CORE_H
