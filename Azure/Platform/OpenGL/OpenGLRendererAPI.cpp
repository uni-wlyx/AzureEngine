#include "azpch.h"
#include "OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace Azure
{
    void OpenGLRendererAPI::SetClearColor(const glm::vec4 &color)
    {
        glClearColor(color.x, color.y, color.z,color.a);
    }

    void OpenGLRendererAPI::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    void OpenGLRendererAPI::DrawIndexed(const Ref<VertexArray> &vertexArray)
    {
        vertexArray->Bind();

        glDrawElements(GL_TRIANGLES,vertexArray->GetIndexBuffer()->GetCount(),GL_UNSIGNED_INT, nullptr);
    }
    void OpenGLRendererAPI::SetViewport(int width, int height)
    {
        glViewport(0,0,width,height);
    }

    void OpenGLRendererAPI::Init() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LINE_SMOOTH);
    }
}
