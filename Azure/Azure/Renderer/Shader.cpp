#include <azpch.h>
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Azure
{
    Ref<Shader> Shader::Create(const std::string &vertexSrc, const std::string &fragmentSrc)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None: AZ_CORE_ASSERT(false,"No Renderer API!!!");
            case RendererAPI::API::OpenGL: return CreateRef<OpenGLShader>(vertexSrc,fragmentSrc);
        }
        AZ_ASSERT(false, "UnKonwn Renderer API!!!");
        return nullptr;
    }

    Ref<Shader> Shader::Create(const std::string &filePath)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None: AZ_CORE_ASSERT(false,"No Renderer API!!!");
            case RendererAPI::API::OpenGL: return CreateRef<OpenGLShader>(filePath);
        }
        AZ_ASSERT(false, "UnKonwn Renderer API!!!");
        return nullptr;
    }

} // Azure