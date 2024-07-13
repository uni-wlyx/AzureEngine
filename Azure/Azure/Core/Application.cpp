
#include "Application.h"
#include "Azure/Log/AzureLog.h"
#include "Input.h"
#include <glad/glad.h>

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

        glGenVertexArrays(1, &m_VertexArray);
        glBindVertexArray(m_VertexArray);

        glGenBuffers(1, &m_VertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

        float vertices[3 * 3] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
            };

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

        glGenBuffers(1, &m_IndexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);

        uint32_t indices[3] = {0, 1, 2};
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices), indices,GL_STATIC_DRAW);
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (m_running)
        {
            glClearColor(0.1f, 0.1f, 0.1f, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            glBindVertexArray(m_VertexArray);
            glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,nullptr);

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

}
