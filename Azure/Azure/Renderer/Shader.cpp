#include <azpch.h>
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Azure
{
    Ref<Shader> Shader::Create(const std::string &name,const std::string &vertexSrc, const std::string &fragmentSrc)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None: AZ_CORE_ASSERT(false,"No Renderer API!!!");
            case RendererAPI::API::OpenGL: return CreateRef<OpenGLShader>(name,vertexSrc,fragmentSrc);
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

    void ShaderLibrary::Add(const Ref<Shader> &shaderSource)
    {
        auto& name = shaderSource->GetName();
        Add(name, shaderSource);
    }

    void ShaderLibrary::Add(const std::string &name, const Ref<Shader> &shaderSource)
    {
        AZ_CORE_ASSERT(!Exists(name),"Shader already exits!");
        m_Shader[name] = shaderSource;
    }

    Ref<Shader> ShaderLibrary::Load(const std::string &filePath)
    {
        auto shader = Shader::Create(filePath);
        Add(shader);
        return shader;
    }

    Ref<Shader> ShaderLibrary::Load(const std::string &name, const std::string &filePath)
    {
        auto shader = Shader::Create(filePath);
        Add(name,shader);
        return shader;
    }

    Ref<Shader> ShaderLibrary::Get(const std::string &name)
    {
        AZ_CORE_ASSERT(Exists(name),"Shader not found!");
        return m_Shader[name];
    }

    bool ShaderLibrary::Exists(const std::string &name)
    {
        return m_Shader.find(name)!= m_Shader.end();
    }

} // Azure