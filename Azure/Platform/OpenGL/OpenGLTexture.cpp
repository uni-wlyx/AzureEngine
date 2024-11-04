#include "azpch.h"
#include "OpenGLTexture.h"

#include <stb_image.h>

namespace Azure
{

    namespace Utils
    {
        static GLenum AzureImageFormatToGLDataFormat(ImageFormat format)
        {
            switch (format)
            {
            case ImageFormat::RGB8:
                return GL_RGB;
            case ImageFormat::RGBA8:
                return GL_RGBA;
            }
            AZ_CORE_ASSERT(false);
            return 0;
        };

        static GLenum HazelImageFormatToGLInternalFormat(ImageFormat format)
        {
            switch (format)
            {
            case ImageFormat::RGB8:
                return GL_RGB8;
            case ImageFormat::RGBA8:
                return GL_RGBA8;
            }

            AZ_CORE_ASSERT(false);
            return 0;
        }
    }

    OpenGLTexture2D::OpenGLTexture2D(const TextureSpecification &specification)
        : m_specification(specification), m_width(specification.Width), m_height(specification.Height)
    {
        m_internalFormat = Utils::HazelImageFormatToGLInternalFormat(m_specification.Format);
        m_dataFormat = Utils::AzureImageFormatToGLDataFormat(m_specification.Format);

        glCreateTextures(GL_TEXTURE_2D, 1, &m_rendererID);
        glTextureStorage2D(m_rendererID, 1, m_internalFormat, m_width, m_height);

        glTextureParameteri(m_rendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(m_rendererID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTextureParameteri(m_rendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTextureParameteri(m_rendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

    OpenGLTexture2D::OpenGLTexture2D(const std::string &path)
    {
        int width, height, channels;

        stbi_set_flip_vertically_on_load(1);
        stbi_uc *data = nullptr;

        data = stbi_load(path.c_str(), &width, &height, &channels, 0);
        if (data)
        {
            m_isLoaded = true;

            m_width = width;
            m_height = height;
        }
    }

    OpenGLTexture2D::~OpenGLTexture2D()
    {
        glDeleteTextures(1, &m_rendererID);
    }

    void OpenGLTexture2D::SetData(void *data, uint32_t size)
    {
    }

    void OpenGLTexture2D::Bind(uint32_t slot) const
    {
        glBindTextureUnit(slot, m_rendererID);
    }

    bool OpenGLTexture2D::operator==(const Texture &other) const
    {
        return m_rendererID == other.GetRendererID();
    }

} // namespace Azure
