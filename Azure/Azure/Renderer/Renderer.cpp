#include <azphc.h>
#include "Renderer.h"

#include "RenderCommand.h"

namespace Azure
{
    void Renderer::BeginScene()
    {
    }

    void Renderer::EndScene()
    {
    }

    void Renderer::Submit(const Ref<Shader> &shader, const Ref<VertexArray> &vertexArray)
    {
        shader->Bind();

        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }

} // namespace Azure
