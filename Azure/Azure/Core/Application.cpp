
#include "Application.h"
#include "Azure/Log/AzureLog.h"
#include "Input.h"

#include <glad/glad.h>

#include "Azure/Renderer/RenderCommand.h"
#include "Azure/Renderer/Renderer.h"
#include "Azure/Renderer/Buffer.h"

#include "Azure/Camera/Camera.h"

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
            for (Layer *layer : m_layerStack)
            {
                layer->OnUpdate();
            }

            m_ImGuiLayer->Begin();
            for (Layer *layer : m_layerStack)
            {
                layer->OnImGuiRender();
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

    void Application::OnEvent(Azure::Event &event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(AZ_BIND_EVENT(Application::OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(AZ_BIND_EVENT(Application::OnWindowResize));

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
        return true;
    }
}
