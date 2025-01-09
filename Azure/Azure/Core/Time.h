#ifndef TIME_H
#define TIME_H

#pragma once

#include "Azure/Core.h"

#include "SDL.h"

namespace Azure
{
    class Time
    {
    public:
        static float GetTime(){
            return SDL_GetTicks()/1000.f;  
        };
    };
} // namespace Azure

#endif