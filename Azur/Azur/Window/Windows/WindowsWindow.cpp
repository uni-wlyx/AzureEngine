#include "azphc.h"
#include "WindowsWindow.h"

#include "Azur/Events/ApplicationEvent.h"
#include "Azur/Events/KeyEvent.h"
#include "Azur/Events/MouseEvent.h"

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

        int status = gladLoadGLLoader((GLADloadproc ) glfwGetProcAddress);
        AZ_CORE_ASSERT(status,"Failed to initialize Glad");

        glfwSetWindowUserPointer(m_window, &m_Data);
        glfwSetWindowSizeCallback(m_window, [](GLFWwindow *window, int width, int height) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_window, [](GLFWwindow *window) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT: {
                    KeyPressedEvent event(key, true);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(m_window, [](GLFWwindow *window, int button, int action, int mods) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            }
        });

    }

    void WindowsWindow::ShutDown() {
        glfwDestroyWindow(m_window);
    }
}