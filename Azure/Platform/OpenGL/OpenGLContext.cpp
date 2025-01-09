#include "azpch.h"
#include "OpenGLContext.h"

#include "glad/glad.h"
#include "SDL.h"


namespace Azure
{

    void OpenGLContext::Init(const void *window)
    {
        AZ_CORE_ASSERT(window, "Window handle is null");

        m_windowHandle = (SDL_Window *)window;

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        m_context = SDL_GL_CreateContext(m_windowHandle);
        AZ_CORE_ASSERT(m_context,"Failed to create sdl2 context:{}",SDL_GetError());
        SDL_GL_MakeCurrent(m_windowHandle, m_context);

        int status = gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
        AZ_CORE_ASSERT(status, "Failed to initialize glad");

        AZ_CORE_INFO("Window API: SDL2");
        //TODO : info abstract
        AZ_CORE_INFO("OpenGL Info:");
        AZ_CORE_INFO("  Vendor: {0}", (const char *)glGetString(GL_VENDOR));
        AZ_CORE_INFO("  Renderer: {0}", (const char *)glGetString(GL_RENDERER));
        AZ_CORE_INFO("  GLSL Version: {0}", (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION));
        AZ_CORE_INFO("  Version: {0}", (const char *)glGetString(GL_VERSION));
    }
    void OpenGLContext::ShutDown()
    {
        SDL_GL_DeleteContext(m_context);
    }
    void OpenGLContext::SwapBuffers()
    {
        SDL_GL_SwapWindow(m_windowHandle);
    }
}