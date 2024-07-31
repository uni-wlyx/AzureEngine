
#ifndef WINDOW_H
#define WINDOW_H

#include "azpch.h"

#include "Azure/Core.h"
#include "Azure/Events/Event.h"

namespace Azure {

    struct WindowProps {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        explicit WindowProps(const std::string &title = "Azure Engine", unsigned int width = 1280,
                             unsigned int height = 720)
                : Title(title), Width(width), Height(height) {

        }
    };

    class AZURE_API Window {
    public:
        using EventCallbackFn = std::function<void(Event &)>;

        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;

        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn &callback) = 0;

        virtual void Init(const WindowProps &props = WindowProps()) = 0;

        virtual void ShutDown() = 0;

        static Scope<Window> Create();

        virtual void *GetNativeWindow() const = 0;
    };
}


#endif //WINDOW_H
