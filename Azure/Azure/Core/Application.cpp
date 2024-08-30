
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


        m_vertexArray = VertexArray::Create();

        float vertices[6 * 3] = {
            -0.5f, -0.5f, 0.0f,0.6f,0.34f,0.67f,
            0.5f, -0.5f, 0.0f,0.38f,0.85f,0.75f,
            0.0f, 0.5f, 0.0f,0.44f,0.66f,0.28f};

        Ref<VertexBuffer> vb = VertexBuffer::Create(vertices, sizeof(vertices));
        vb->SetLayout({
            {EShaderDataType::Float3, "a_Postion"},
            {EShaderDataType::Float3, "a_Color"}
        });

        m_vertexArray->AddVertexBuffer(vb);

        uint32_t indices[3] = {0, 1, 2};
        Ref<IndexBuffer> ib = IndexBuffer::Create(indices, sizeof(indices));

        m_vertexArray->SetIndexBuffer(ib);

        std::string vertexSrc = "#version 330 core\n"
                                "layout (location = 0) in vec3 aPos;\n"
                                "layout (location = 1) in vec3 aColor;\n"
                                "uniform mat4 u_ViewProjection;\n"
                                "out vec3 vColor;\n"
                                "void main()\n"
                                "{\n"
                                "vColor = aColor;"
                                "gl_Position = u_ViewProjection * vec4(aPos.x, aPos.y, aPos.z, 1.0) ;\n"
                                "}\n";

        std::string fragmentSrc = "#version 330 core\n"
                                  "out vec4 FragColor;\n"
                                  "in vec3 vColor;\n"
                                  "void main()\n"
                                  "{\n"
                                  "FragColor = vec4(vColor,1.0f);\n"
                                  "}\n";

        m_shader = CreateRef<Shader>(vertexSrc, fragmentSrc);

        m_camera = OrthographicCamera({0,0,0});
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (m_running)
        {
            RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1});
            RenderCommand::Clear();

            Renderer::BeginScene(m_camera);

            Renderer::Submit(m_shader,m_vertexArray);

            Renderer::EndScene();

          
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
