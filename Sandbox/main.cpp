#include <iostream>
#include <Azure.h>

class ExampleLayer : public Azure::Layer
{
public:
    ExampleLayer()
    {
        m_vertexArray = Azure::VertexArray::Create();

        float len2 = 0.5;
        float wid2 = 0.5;
        float hei2 = 0.5;

        float vertexs[] = {
            len2,
            hei2,
            -wid2,
            0.6f,
            0.34f,
            0.67f,
            -len2,
            hei2,
            -wid2,
            0.38f,
            0.85f,
            0.75f,
            -len2,
            hei2,
            wid2,
            0.44f,
            0.66f,
            0.28f,
            len2,
            hei2,
            wid2,
            0.6f,
            0.34f,
            0.67f,

            len2,
            -hei2,
            -wid2,
            0.38f,
            0.85f,
            0.75f,
            -len2,
            -hei2,
            -wid2,
            0.44f,
            0.66f,
            0.28f,
            -len2,
            -hei2,
            wid2,
            0.6f,
            0.34f,
            0.67f,
            len2,
            -hei2,
            wid2,
            0.44f,
            0.66f,
            0.28f,

        };

        float vertices[6 * 3] = {
            -0.5f, -0.5f, 0.0f, 0.6f, 0.34f, 0.67f,
            0.5f, -0.5f, 0.0f, 0.38f, 0.85f, 0.75f,
            0.0f, 0.5f, 0.0f, 0.44f, 0.66f, 0.28f};

        Azure::Ref<Azure::VertexBuffer> vb = Azure::VertexBuffer::Create(vertexs, sizeof(vertexs));
        vb->SetLayout({{Azure::EShaderDataType::Float3, "a_Postion"},
                       {Azure::EShaderDataType::Float3, "a_Color"}});

        m_vertexArray->AddVertexBuffer(vb);

        // uint32_t indices[3] = {0, 1, 2};

        uint32_t indices[] = {
            0,
            1,
            2,
            0,
            2,
            3,
            0,
            4,
            7,
            0,
            7,
            3,
            3,
            7,
            6,
            3,
            6,
            2,
            1,
            5,
            6,
            1,
            6,
            2,
            0,
            4,
            5,
            0,
            1,
            5,
            4,
            7,
            5,
            5,
            6,
            7,
        };

        Azure::Ref<Azure::IndexBuffer> ib = Azure::IndexBuffer::Create(indices, sizeof(indices));

        m_vertexArray->SetIndexBuffer(ib);

        std::string vertexSrc = "#version 330 core\n"
                                "layout (location = 0) in vec3 aPos;\n"
                                "layout (location = 1) in vec3 aColor;\n"

                                "uniform mat4 u_Transform;;\n"
                                "uniform mat4 u_ViewProjection;\n"
                                "out vec3 vColor;\n"
                                "void main()\n"
                                "{\n"
                                "vColor = aColor;"
                                "gl_Position = u_ViewProjection * u_Transform * vec4(aPos.x, aPos.y, aPos.z, 1.0) ;\n"
                                "}\n";

        std::string fragmentSrc = "#version 330 core\n"
                                  "out vec4 FragColor;\n"
                                  "in vec3 vColor;\n"
                                  "void main()\n"
                                  "{\n"
                                  "FragColor = vec4(vColor,1.0f);\n"
                                  "}\n";

        m_shader = Azure::CreateRef<Azure::Shader>(vertexSrc, fragmentSrc);

        m_camera = Azure::Camera::CreateOrthographic();
        m_camera.SetPosition({0, 0, 0});
        m_camera.SetRotation({0, 0, 0});
    }

    float spp = 0;

    void OnUpdate(float deltaTime) override
    {

        spp++;
        // m_camera.SetRotation({0,0, spp});

        Azure::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1});
        Azure::RenderCommand::Clear();

        Azure::Renderer::BeginScene(m_camera);

        Azure::Renderer::Submit(m_shader, m_vertexArray);

        Azure::Renderer::EndScene();
    }

    virtual void OnImGuiRender(ImGuiContext * context) override
    {

        ImGui::SetCurrentContext(context);
        ImGuiIO& io = ImGui::GetIO();
        ImGui::Begin("xxx");
         ImGui::Text("FPS:%.1f/%.3f ms", io.Framerate, 1000.0f / io.Framerate);


          if (ImGui::Button("o"))
          {
              m_camera.SetCameraType(Azure::ECameraType::Orthographic);
          }
          if (ImGui::Button("p"))
          {
              m_camera.SetCameraType(Azure::ECameraType::Perspective);
          }

        ImGui::End();

//         ImGui::ShowDemoWindow();
        // ImGui::Begin("qwewq");
        // // if (ImGui::Button("o"))
        // // {
        // //     m_camera.SetCameraType(Azure::ECameraType::Orthographic);
        // // }
        // // if (ImGui::Button("p"))
        // // {
        // //     m_camera.SetCameraType(Azure::ECameraType::Perspective);
        // // }

        // ImGui::End();
    };

    void OnEvent(Azure::Event &event) override
    {
    }

private:
    Azure::Camera m_camera;
    Azure::Ref<Azure::VertexArray> m_vertexArray;
    Azure::Ref<Azure::Shader> m_shader;
};

// class

int main()
{
    Azure::AzureLog::Init();

    AZ_CORE_INFO("Init Log");

    auto *app = Azure::Application::CreateApp();
    app->PushOverlay(new ExampleLayer());
    //    app->PushOverlay(new Azure::ImGuiLayer());
    app->Run();
    delete app;

    return 0;
}
