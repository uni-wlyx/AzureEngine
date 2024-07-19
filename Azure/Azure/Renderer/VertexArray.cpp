#include "azphc.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "RendererAPI.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Azure{
    VertexArray *VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::OpenGL:  return new OpenGLVertexArray ();
        case RendererAPI::API::None:    AZ_ASSERT(false, "No Renderer API!!!");return nullptr;
        }

        AZ_ASSERT(false, "UnKonwn Renderer API!!!");
        return nullptr;
    }
}