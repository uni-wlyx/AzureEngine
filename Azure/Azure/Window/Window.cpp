#include "azphc.h"
#include "Window.h"

#ifdef AZURE_PLATFORM_WINDOWS

#include "Platform/Windows/WindowsWindow.h"

#endif

namespace Azure {
    Scope <Window> Window::Create(const Azure::WindowProps &props) {
    #ifdef AZURE_PLATFORM_WINDOWS
        return CreateScope<WindowsWindow>(props);
    #else
        AZ_CORE_ASSERT(false,"Unknown platform");
        return nullptr;
    #endif
    }
}