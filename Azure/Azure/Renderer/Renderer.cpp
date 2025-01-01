#include <azpch.h>
#include "Renderer.h"

#include "RenderCommand.h"

namespace Azure
{

    Scope<Renderer::SceneData> Renderer::s_SceneData = CreateScope<Renderer::SceneData>();
    Scope<ShaderLibrary> Renderer::s_ShaderLibrary = CreateScope<ShaderLibrary>();

    void Renderer::Init() {
        RenderCommand::Init();
    }

    void Renderer::Shutdown() {

    }


    void Renderer::BeginScene(Camera &camera)
    {
        s_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
    }

    void Renderer::EndScene()
    {
    }

    void Renderer::Submit(const Ref<Shader> &shader, const Ref<VertexArray> &vertexArray,const glm::mat4& transform)
    {
        shader->Bind();
        shader->SetMat4("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
        shader->SetMat4("u_Transform",transform);
        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }


} // namespace Azure
