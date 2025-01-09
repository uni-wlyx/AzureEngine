#include "azpch.h"
#include "SDLWindow.h"

#include "Azure/Events/ApplicationEvent.h"
#include "Azure/Events/KeyEvent.h"
#include "Azure/Events/MouseEvent.h"

#include "Azure/Core/Input.h"

#include <imgui_impl_sdl2.h>

namespace Azure
{
    static bool s_SDLInitialized = false;

    SDLWindow::SDLWindow()
    {
    }

    SDLWindow::~SDLWindow()
    {
    }

    void SDLWindow::Init(const WindowProps &props)
    {
        m_data.Title = props.Title;
        m_data.Width = props.Width;
        m_data.Height = props.Height;
        AZ_CORE_INFO("Create Window {0}({1},{2})", m_data.Title, m_data.Width, m_data.Height);

        if (!s_SDLInitialized)
        {
            int success = SDL_Init(SDL_INIT_EVERYTHING);

            AZ_CORE_ASSERT(success == 0, "Failed to initialize SDL,Error: %s", SDL_GetError());

            // AZ_CORE_ASSERT(success, SDL_GetErrorMsg());

            s_SDLInitialized = true;
        }

        m_window = SDL_CreateWindow(m_data.Title.c_str(),
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    m_data.Width, m_data.Height,
                                    SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
        m_context = GraphicsContext::Create();
        m_context->Init(m_window);
        // m_context = new Ope
    }

    void SDLWindow::OnUpdate()
    {
        // SDL_AddEventWatch
        // SDL_GetKeyFromScancode()

        while (SDL_PollEvent(&sdlEvent))
        {
            ImGui_ImplSDL2_ProcessEvent(&sdlEvent);
            switch (sdlEvent.type)
            {
            case SDL_WINDOWEVENT:
            {
                if (sdlEvent.window.event == SDL_WINDOWEVENT_RESIZED)
                {
                    m_data.Width = sdlEvent.window.data1;
                    m_data.Height = sdlEvent.window.data2;
                    WindowResizeEvent event(m_data.Width, m_data.Height);
                    m_data.EventCallback(event);
                }
                break;
            }

            case SDL_KEYDOWN:
            {
                if (sdlEvent.key.repeat)
                {
                    KeyPressedEvent event(sdlEvent.key.keysym.scancode, true);
                    m_data.EventCallback(event);
                }
                else
                {
                    KeyPressedEvent event(sdlEvent.key.keysym.scancode);
                    m_data.EventCallback(event);
                }
                break;
            }

            case SDL_KEYUP:
            {
                KeyReleasedEvent event(sdlEvent.key.keysym.scancode);
                m_data.EventCallback(event);
                break;
            }

            case SDL_MOUSEBUTTONDOWN:
            {
                MouseButtonPressedEvent event(sdlEvent.button.button);
                m_data.EventCallback(event);
                break;
            }

            case SDL_MOUSEBUTTONUP:
            {
                MouseButtonReleasedEvent event(sdlEvent.button.button);
                m_data.EventCallback(event);
                break;
            }

            case SDL_QUIT:
            {
                WindowCloseEvent event;
                m_data.EventCallback(event);
                break;
            }
            }
        }

        m_context->SwapBuffers();
    }
    void *SDLWindow::GetNativeWindow() const
    {
        return m_window;
    }

    void SDLWindow::ShutDown()
    {
        m_context->ShutDown();
        SDL_DestroyWindow(m_window);
    }
}
