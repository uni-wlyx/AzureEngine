
#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>


namespace Azure
{

    class AZURE_API Shader
    {
    public:
        Shader(const std::string &vertexSrc, const std::string &fragmentSrc);

        ~Shader();

        virtual void Bind() const;

        virtual void UnBind() const;

        void UploadUniformMat4(const std::string &name, const glm::mat4 &matrix);

    private:
        uint32_t m_RendererID;
    };

} // Azure

#endif // SHADER_H
