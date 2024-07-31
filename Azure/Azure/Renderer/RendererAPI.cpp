#include "azpch.h"
#include "RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Azure
{
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;
    Scope<RendererAPI> RendererAPI::Create()
    {
        switch (s_API)
        {
        case RendererAPI::API::OpenGL:  return CreateScope<OpenGLRendererAPI>();
        case RendererAPI::API::None: AZ_CORE_ASSERT(false,"RendererAPI::None is currently not supported!") return nullptr; 
        }

        AZ_CORE_ASSERT(false,"Unknown RendererAPI!");
        return nullptr;
    }
} // namespace Azure
