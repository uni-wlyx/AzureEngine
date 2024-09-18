#include <azpch.h>
#include "OpenGLShader.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

namespace Azure
{
    OpenGLShader::OpenGLShader(const std::string &vertexSrc, const std::string &fragmentSrc)
    {
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

        const GLchar *source = vertexSrc.c_str();
        glShaderSource(vertexShader, 1, &source, 0);

        glCompileShader(vertexShader);

        GLint isCompiled = 0;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
        if (isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);
            glDeleteShader(vertexShader);

            AZ_CORE_ERROR("{0}", infoLog.data());
            AZ_ASSERT(false, "Vertex shader compilation failed!");
            return;
        }

        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        source = fragmentSrc.c_str();
        glShaderSource(fragmentShader, 1, &source, 0);

        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
        if (isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);
            glDeleteShader(fragmentShader);
            glDeleteShader(vertexShader);

            AZ_CORE_ERROR("{0}", infoLog.data());
            AZ_ASSERT(false, "Fragment shader compilation failed!");
            return;
        }

        m_rendererID = glCreateProgram();

        glAttachShader(m_rendererID, vertexShader);
        glAttachShader(m_rendererID, fragmentShader);

        glLinkProgram(m_rendererID);
        GLint isLinked = 0;
        glGetProgramiv(m_rendererID, GL_LINK_STATUS, &isLinked);
        if (isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(m_rendererID, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<char> infoLog(maxLength);
            glGetProgramInfoLog(m_rendererID, maxLength, &maxLength, &infoLog[0]);

            glDeleteProgram(m_rendererID);
            glDeleteShader(fragmentShader);
            glDeleteShader(vertexShader);

            AZ_CORE_ERROR("{0}", infoLog.data());
            AZ_ASSERT(false, "Shader link failed!");
            return;
        }

        glDetachShader(m_rendererID, vertexShader);
        glDetachShader(m_rendererID, fragmentShader);
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(m_rendererID);
    }

    void OpenGLShader::Bind() const
    {
        glUseProgram(m_rendererID);
    }

    void OpenGLShader::UnBind() const
    {
        glUseProgram(0);
    }

    void OpenGLShader::SetInt(const std::string &name, int value)
    {
        UploadUniformInt(name, value);
    }

    void OpenGLShader::SetIntArray(const std::string &name, int *values, uint32_t count)
    {
        UploadUniformIntArray(name, values, count);
    }

    void OpenGLShader::SetFloat(const std::string &name, float value)
    {
        UploadUniformFloat(name, value);
    }

    void OpenGLShader::SetFloat2(const std::string &name, const glm::vec2 &value)
    {
        UploadUniformFloat2(name, value);
    }

    void OpenGLShader::SetFloat3(const std::string &name, const glm::vec3 &value)
    {
        UploadUniformFloat3(name,value);
    }

    void OpenGLShader::SetFloat4(const std::string &name, const glm::vec4 &value)
    {
        UploadUniformFloat4(name,value);
    }

    void OpenGLShader::SetMat4(const std::string &name, const glm::mat4 &value)
    {
        UploadUniformMat4(name,value);
    }

    void OpenGLShader::UploadUniformInt(const std::string &name, int value)
    {
        GLint location = glGetUniformLocation(m_rendererID, name.c_str());
        glUniform1i(location, value);
    }

    void OpenGLShader::UploadUniformIntArray(const std::string &name, int *values, uint32_t count)
    {
        GLint location = glGetUniformLocation(m_rendererID, name.c_str());
		glUniform1iv(location, count, values);
    }

    void OpenGLShader::UploadUniformFloat(const std::string &name, float value)
    {
        GLint location = glGetUniformLocation(m_rendererID, name.c_str());
        glUniform1f(location, value);
    }

    void OpenGLShader::UploadUniformFloat2(const std::string &name, const glm::vec2 &value)
    {
        GLint location = glGetUniformLocation(m_rendererID, name.c_str());
        glUniform2f(location, value.x, value.y);
    }

    void OpenGLShader::UploadUniformFloat3(const std::string &name, const glm::vec3 &value)
    {
        GLint location = glGetUniformLocation(m_rendererID, name.c_str());
        glUniform3f(location, value.x, value.y, value.z);
    }

    void OpenGLShader::UploadUniformFloat4(const std::string &name, const glm::vec4 &value)
    {
        GLint location = glGetUniformLocation(m_rendererID, name.c_str());
        glUniform4f(location, value.x, value.y, value.z, value.w);
    }

    void OpenGLShader::UploadUniformMat3(const std::string &name, const glm::mat3 &matrix)
    {
        GLint location = glGetUniformLocation(m_rendererID, name.c_str());
        glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::UploadUniformMat4(const std::string &name, const glm::mat4 &matrix)
    {
        GLint location = glGetUniformLocation(m_rendererID, name.c_str());
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }
} // Azure