#include "azpch.h"
#include "GraphicsContext.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLContext.h"


namespace Azure{

    Ref<GraphicsContext> GraphicsContext::Create()
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None: AZ_CORE_ASSERT(false,"No Renderer API!!!");
            case RendererAPI::API::OpenGL: return CreateRef<OpenGLContext>();
        }
        AZ_ASSERT(false, "UnKonwn Renderer API!!!");
        return nullptr;
    }


}