
#include "azpch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Azure {

    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle) : m_windowHandle(windowHandle) {
        AZ_CORE_ASSERT(m_windowHandle,"Window handle is null");
    }

    void OpenGLContext::Init() {
        glfwMakeContextCurrent(m_windowHandle);
        int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        AZ_CORE_ASSERT(status, "Failed to initialize Glad");

        AZ_CORE_INFO("OpenGL Info:");
        AZ_CORE_INFO("  Vendor: {0}", (const char *) glGetString(GL_VENDOR));
        AZ_CORE_INFO("  Renderer: {0}", (const char *) glGetString(GL_RENDERER));
        AZ_CORE_INFO("  GLSL Version: {0}", (const char *) glGetString(GL_SHADING_LANGUAGE_VERSION));
        AZ_CORE_INFO("  Version: {0}", (const char *) glGetString(GL_VERSION));
        
//        GL_g
    }

    void OpenGLContext::SwapBuffers() {
        glfwSwapBuffers(m_windowHandle);
    }


}