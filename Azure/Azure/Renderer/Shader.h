
#ifndef SHADER_H
#define SHADER_H

namespace Azure {

    class Shader {
    public:
        Shader(const std::string &vertexSrc, const std::string &fragmentSrc);

        ~Shader();

        virtual void Bind() const;

        virtual void UnBind() const;

    private:
        uint32_t m_RendererID;
    };

} // Azure

#endif //SHADER_H
