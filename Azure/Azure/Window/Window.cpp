#include "azpch.h"
#include "Window.h"

// #ifdef AZURE_PLATFORM_WINDOWS

#include "Platform/Windows/WindowsWindow.h"

// #endif

namespace Azure {
    Scope <Window> Window::Create() {

                return CreateScope<WindowsWindow>();
    #ifdef AZURE_PLATFORM_WINDOWS
        // return CreateScope<WindowsWindow>();
    #else
        // AZ_CORE_ASSERT(false,"Unknown platform");
        return nullptr;
    #endif
    }
}