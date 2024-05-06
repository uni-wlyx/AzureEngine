#include "azphc.h"
#include "WindowsWindow.h"

namespace Azur {

    static bool s_GLFWInitialized = false;

    Window *Window::Create(const WindowProps &props) {
        return new WindowsWindow(props);
    }


    WindowsWindow::WindowsWindow(const WindowProps &props) {
        Init(props);
    }

    WindowsWindow::~WindowsWindow() {
        ShutDown();
    }

    void WindowsWindow::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_window);

    }

    void WindowsWindow::Init(const WindowProps &props) {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;
        AZ_CORE_INFO("Create Window {0}({1},{2})", m_Data.Title, m_Data.Width, m_Data.Height);

        if (!s_GLFWInitialized) {
            int success = glfwInit();
            AZ_CORE_ASSERT(success, "Failed to initialize GLFW");


//            if (!success) {
//                AZ_CORE_ERROR("Failed to initialize GLFW");
//            } else {
//                AZ_CORE_INFO("Initialized GLFW");
//            };
            s_GLFWInitialized = true;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow((int) m_Data.Width, (int) m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_window);

    }

    void WindowsWindow::ShutDown() {
        glfwDestroyWindow(m_window);
    }
}