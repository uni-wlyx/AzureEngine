
#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#include "Azure/Window/Window.h"
#include "Azure/Renderer/GraphicsContext.h"

#ifdef AZURE_WINODW_API_GLFW

    #include <GLFW/glfw3.h>
//#include "Platform/OpenGL/OpenGLContext.h"

namespace Azure {

    class WindowsWindow : public Window {
    public:
        explicit WindowsWindow();

        ~WindowsWindow() override;

        void OnUpdate() override;

        unsigned int GetWidth() const override { return m_Data.Width; };

        unsigned int GetHeight() const override { return m_Data.Height; };

        void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback ;}

        void * GetNativeWindow() const override;

    // private:
        void Init(const WindowProps &props = WindowProps()) override;

        void ShutDown() override;

    private:
        GLFWwindow *m_window;
        Ref <GraphicsContext> m_context;

        struct WindowData {
            std::string Title;
            unsigned int Width, Height;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
}


#endif // AZURE_WINODW_API_GLFW


#endif //WINDOWSWINDOW_H
