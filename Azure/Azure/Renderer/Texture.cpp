#include "azpch.h"
#include "Texture.h"

#include "Azure/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Azure
{

    Ref<Texture2D> Texture2D::Create(const TextureSpecification &specification)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None: AZ_CORE_ASSERT(false,"No Renderer API!!!");
            case RendererAPI::API::OpenGL: return CreateRef<OpenGLTexture2D>(specification);
        }
        AZ_ASSERT(false, "UnKonwn Renderer API!!!");
        return nullptr;
    }

    Ref<Texture2D> Texture2D::Create(const std::string &path)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None: AZ_CORE_ASSERT(false,"No Renderer API!!!");
            case RendererAPI::API::OpenGL: return CreateRef<OpenGLTexture2D>(path);
        }
        AZ_ASSERT(false, "UnKonwn Renderer API!!!");
        return nullptr;
    }

} // namespace Azure
