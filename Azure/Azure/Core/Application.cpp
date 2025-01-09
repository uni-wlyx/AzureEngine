
#include "Application.h"
#include "Azure/Log/AzureLog.h"
#include "Input.h"

#include <glad/glad.h>

#include "Azure/Renderer/RenderCommand.h"
#include "Azure/Renderer/Renderer.h"
#include "Azure/Renderer/Buffer.h"

#include "Azure/Camera/Camera.h"

#include "Azure/Core/Time.h"

namespace Azure
{
    Application *Application::s_instance = nullptr;

    Application::Application()
    {
        AZ_CORE_ASSERT(!s_instance, "Application already exists");
        s_instance = this;

        m_window = Window::Create();
        m_window->Init();
        m_window->SetEventCallback(AZ_BIND_EVENT(Application::OnEvent));

        Renderer::Init();

        m_ImGuiLayer = new ImGuiLayer();
        // stack会自动管理指针
        PushOverlay(m_ImGuiLayer);
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {

        while (m_running)
        {

            float time = Time::GetTime();
            float deltaTime = time - m_lastUpdateTime;
            m_lastUpdateTime = time;

            for (Layer *layer : m_layerStack)
            {
                layer->OnUpdate(deltaTime);
            }

            m_ImGuiLayer->Begin();
            for (Layer *layer : m_layerStack)
            {
                layer->OnImGuiRender(m_ImGuiLayer->GetContext());
            }
            m_ImGuiLayer->End();

            m_window->OnUpdate();
        }
        m_window->ShutDown();
    }

    void Application::PushLayer(Layer *layer)
    {
        m_layerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *overlay)
    {
        m_layerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }

    Application *Azure::Application::CreateApp()
    {
        return new Application();
    }

    bool Mousss(MouseButtonPressedEvent &event)
    {
        // if (event.GetMouseButton() == Mouse::ButtonLeft)
        // {
        //     AZ_INFO("Mouse:left");

        //     uint32_t mouseButton = SDL_GetMouseState(0, 0);

        //     AZ_INFO("Event:{}", (SDL_BUTTON(Mouse::ButtonLeft) & mouseButton)!=0 );
        // }
        

        // if (event.GetMouseButton() == Mouse::ButtonRight)
        // {
        //     AZ_INFO("Mouse:right");

        //     uint32_t mouseButton = SDL_GetMouseState(0, 0);
        //     AZ_INFO("Event:{}", (SDL_BUTTON(Mouse::ButtonRight) & mouseButton)!=0 );
        // }
        // if (event.GetMouseButton() == Mouse::ButtonMiddle)
        // {
        //     AZ_INFO("Mouse:mid");

        //     uint32_t mouseButton = SDL_GetMouseState(0, 0);
        //     AZ_INFO("Event:{}", (SDL_BUTTON(Mouse::ButtonMiddle) & mouseButton)!=0 );
        // }

        return false;
    }

    void Application::OnEvent(Azure::Event &event)
    {
        EventDispatcher dispatcher(event);
        // AZ_INFO("Event:{}",event.GetName());
        //    uint32_t mouseButton = SDL_GetMouseState(0,0);
        // AZ_INFO("Event:{}",event.GetName());

        dispatcher.Dispatch<WindowCloseEvent>(AZ_BIND_EVENT(Application::OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(AZ_BIND_EVENT(Application::OnWindowResize));
        dispatcher.Dispatch<MouseButtonPressedEvent>(Mousss);

        for (auto iter = m_layerStack.end(); iter != m_layerStack.begin();)
        {
            (*--iter)->OnEvent(event);
            if (event.Handled)
            {
                break; // 当事件被处理，不用传递下去
            }
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_running = false;
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent &e)
    {
        RenderCommand::ResizeViewport(e.GetWidth(), e.GetHeight());
        return false;
    }
}
