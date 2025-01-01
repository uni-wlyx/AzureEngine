
#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <unordered_map>

namespace Azure
{

    class AZURE_API Shader
    {
    public:
        virtual ~Shader() = default;

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

        virtual void SetInt(const std::string &name, int value) = 0;
        virtual void SetIntArray(const std::string &name, int *values, uint32_t count) = 0;
        virtual void SetFloat(const std::string &name, float value) = 0;
        virtual void SetFloat2(const std::string &name, const glm::vec2 &value) = 0;
        virtual void SetFloat3(const std::string &name, const glm::vec3 &value) = 0;
        virtual void SetFloat4(const std::string &name, const glm::vec4 &value) = 0;
        virtual void SetMat4(const std::string &name, const glm::mat4 &value) = 0;

        virtual const std::string &GetName() const = 0;

        static Ref<Shader> Create(const std::string &name,const std::string &vertexSrc, const std::string &fragmentSrc);
        static Ref<Shader> Create(const std::string &filePath);
    };

    class AZURE_API ShaderLibrary
    {
    public:
        void Add(const Ref<Shader>& shaderSource);
        void Add(const std::string& name, const Ref<Shader>& shaderSource);
        Ref<Shader> Load(const std::string& filePath);// shader.glsl
        Ref<Shader> Load(const std::string& name,const std::string& filePath);

        Ref<Shader> Get(const std::string& name);

        bool Exists(const std::string& name);
    private:
        std::unordered_map<std::string,Ref<Shader>> m_Shader;
    };

} // Azure

#endif // SHADER_H
