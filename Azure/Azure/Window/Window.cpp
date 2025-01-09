#include "azpch.h"
#include "Window.h"

// #ifdef AZURE_PLATFORM_WINDOWS

#include "Platform/Common/SDLWindow.h"

// #endif

namespace Azure {
    Scope <Window> Window::Create() {
        return CreateScope<SDLWindow>();
    }
}