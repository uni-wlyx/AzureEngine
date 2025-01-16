#include "azpch.h"
#include "EditorLayer.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Azure
{
    EditorLayer::EditorLayer()
    {
        m_vertexArray = Azure::VertexArray::Create();

        float len2 = 0.5;
        float wid2 = 0.5;
        float hei2 = 0.5;

        float vertexs[] = {
            len2,hei2,-wid2,0,0,
            -len2,hei2,-wid2,0,1,
            -len2,hei2,wid2,1,1,
            len2,hei2,wid2,1,0,

            len2,-hei2,-wid2,0,0,
            -len2,-hei2,-wid2,0,1,
            -len2,-hei2,wid2,1,1,
            len2,-hei2,wid2,1,0,
        };


        // float vertices[6 * 3] = {
        //     -0.5f, -0.5f, 0.0f, 0.6f, 0.34f, 0.67f,
        //     0.5f, -0.5f, 0.0f, 0.38f, 0.85f, 0.75f,
        //     0.0f, 0.5f, 0.0f, 0.44f, 0.66f, 0.28f};

        Azure::Ref<Azure::VertexBuffer> vb = Azure::VertexBuffer::Create(vertexs, sizeof(vertexs));
        vb->SetLayout({
            {Azure::EShaderDataType::Float3, "a_Postion"},
            {Azure::EShaderDataType::Float2, "a_TexCoord"},
        });

        m_vertexArray->AddVertexBuffer(vb);

        // uint32_t indices[3] = {0, 1, 2};

        // 0,1,2,0,2,3,
        // 0,4,7,0,7,3,
        // 3,7,6,3,6,2,
        // 1,5,6,1,6,2,
        // 0,4,5,0,1,5,
        // 4,7,5,5,6,7,
        // uint32_t indices[6*6] = {3
        //     0,1,2,0,2,3,
        //     0,4,7,0,7,3,
        //     3,7,6,3,6,2,
        //     1,5,6,1,6,2,
        //     0,4,5,0,1,5,
        //     4,7,5,5,6,7,
        // };

        uint32_t indices[] = {
            0,1,2,0,2,3,
            0,4,7,0,7,3,
            3,7,6,3,6,2,
                1,2,6,1,6,5,

               0,4,5,0,1,5,
                4,5,6,4,6,7,
        };

        Azure::Ref<Azure::IndexBuffer> ib = Azure::IndexBuffer::Create(indices, sizeof(indices));

        m_vertexArray->SetIndexBuffer(ib);

        std::string vertexSrc = "#version 330 core\n"
                                "layout (location = 0) in vec3 aPos;\n"
                                "layout (location = 1) in vec2 a_TexCoord;\n"

                                "uniform mat4 u_Transform;;\n"
                                "uniform mat4 u_ViewProjection;\n"
                                "out vec2 vTexCoord;\n"
                                "void main()\n"
                                "{\n"
                                "vTexCoord = a_TexCoord;"
                                "gl_Position = u_ViewProjection * u_Transform * vec4(aPos.x, aPos.y, aPos.z, 1.0) ;\n"
                                "}\n";

        std::string fragmentSrc = "#version 330 core\n"
                                  "out vec4 FragColor;\n"
                                  "in vec2 vTexCoord;\n"
                                  "uniform sampler2D uTexture;\n"
                                  "void main()\n"
                                  "{\n"
                                  "FragColor = texture(uTexture,vTexCoord);\n"
                                  "}\n";
        m_shader = Renderer::s_ShaderLibrary->Load("Content/Materials/Texture.glsl");

        m_camera = Azure::Camera::CreatePerspective();
        m_camera.SetPosition({-3, 0, 0});
        m_camera.SetRotation({0, 0, 0});

        m_texture = Azure::Texture2D::Create("Content/Materials/Textures/Checkerboard.png");
        m_shader->Bind();
        m_shader->SetInt("uTexture", 0);
    }

    void EditorLayer::OnUpdate(float deltaTime)
    {
        m_camera.OnUpdate(deltaTime);

        // m_camera.SetPosition(pos);
        spp+=30.0f * deltaTime;
        glm::mat4 model = glm::mat4(1);
        // model = glm::rotate(model,glm::radians(spp),glm::vec3(0,0,1));

        Azure::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1});
        Azure::RenderCommand::Clear();

        Azure::Renderer::BeginScene(m_camera);

        m_texture->Bind();
        Azure::Renderer::Submit(m_shader, m_vertexArray,model);

        Azure::Renderer::EndScene();

    }
    void EditorLayer::OnImGuiRender(ImGuiContext *context)
    {
        ImGui::SetCurrentContext(context);
        ImGuiIO &io = ImGui::GetIO();
        ImGui::Begin("xxx");
        ImGui::Text("FPS:%.1f/%.3f ms", io.Framerate, 1000.0f / io.Framerate);
        ImGui::SliderFloat("xp", &xp, -10, 10);
        ImGui::SliderFloat3("pos", glm::value_ptr(pos), -10, 10);
        if (ImGui::Button("o"))
        {
            m_camera.SetCameraType(Azure::ECameraType::Orthographic);
        }
        if (ImGui::Button("p"))
        {
            m_camera.SetCameraType(Azure::ECameraType::Perspective);
        }

        ImGui::End();
    }
    void EditorLayer::OnEvent(Azure::Event &event)
    {
        
    }
}
