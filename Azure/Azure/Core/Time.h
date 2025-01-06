#ifndef TIME_H
#define TIME_H

#pragma once

#include "Azure/Core.h"


// // #include <glf>
// #ifdef AZURE_PLATFORM_WINDOWS
 #include <GLFW/glfw3.h>
// #endif // AZURE_PLATFORM_WINDOWS


namespace Azure
{
    class Time
    {
    public:
        static float GetTime(){
            #ifdef AZURE_PLATFORM_WINDOWS
                return (float)glfwGetTime();
            #else 
                return 0;
            #endif //AZURE_PLATFORM_WINDOWS    
        };
    };
} // namespace Azure

#endif