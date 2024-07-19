#include "azphc.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "RendererAPI.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Azure{
    Ref<VertexArray> VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::OpenGL:  return  CreateRef<OpenGLVertexArray> ();
        case RendererAPI::API::None:    AZ_ASSERT(false, "No Renderer API!!!");return nullptr;
        }

        AZ_ASSERT(false, "UnKonwn Renderer API!!!");
        return nullptr;
    }
}