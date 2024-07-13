
#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#include "Azure/Window/Window.h"
#include "Azure/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>
//#include "Platform/OpenGL/OpenGLContext.h"

namespace Azure {

    class WindowsWindow : public Window {
    public:
        explicit WindowsWindow(const WindowProps &props);

        ~WindowsWindow() override;

        void OnUpdate() override;

        unsigned int GetWidth() const override { return m_Data.Width; };

        unsigned int GetHeight() const override { return m_Data.Height; };

        void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback ;}

        void * GetNativeWindow() const override;

    private:
        virtual void Init(const WindowProps &props);

        virtual void ShutDown();

    private:
        GLFWwindow *m_window;
        GraphicsContext* m_context;

        struct WindowData {
            std::string Title;
            unsigned int Width, Height;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
}


#endif //WINDOWSWINDOW_H
