
#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>


namespace Azure
{

    class AZURE_API Shader
    {
    public:

        virtual ~Shader() = default;

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

		virtual void SetInt(const std::string& name, int value) = 0;
		virtual void SetIntArray(const std::string& name, int* values, uint32_t count) = 0;
		virtual void SetFloat(const std::string& name, float value) = 0;
		virtual void SetFloat2(const std::string& name, const glm::vec2& value) = 0;
		virtual void SetFloat3(const std::string& name, const glm::vec3& value) = 0;
		virtual void SetFloat4(const std::string& name, const glm::vec4& value) = 0;
		virtual void SetMat4(const std::string& name, const glm::mat4& value) = 0;

	    virtual const std::string& GetName() const = 0;

        static Ref<Shader> Create(const std::string &vertexSrc, const std::string &fragmentSrc);
        static Ref<Shader> Create(const std::string &filePath);
    };

} // Azure

#endif // SHADER_H
