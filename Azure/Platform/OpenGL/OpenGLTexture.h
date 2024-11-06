#ifndef OPENGLTEXTURE_H
#define OPENGLTEXTURE_H

#pragma once 

#include "Azure/Renderer/Texture.h"

#include <glad/glad.h>

namespace Azure
{
    class  OpenGLTexture2D : public Texture2D 
    {
    public:
        OpenGLTexture2D(const TextureSpecification& specification);
        OpenGLTexture2D(const std::string& path);

        virtual ~OpenGLTexture2D();

        virtual const TextureSpecification& GetSpecification() const override { return m_specification;}
        
        virtual uint32_t GetWidth() const override { return m_width; }
        virtual uint32_t GetHeight() const override { return m_height;}
        virtual uint32_t GetRendererID() const override { return m_rendererID; }

        virtual const std::string& GetPath() const override { return m_path; }
        virtual void SetData(void* data,uint32_t size) override;
        virtual void Bind(uint32_t slot = 0) const override;
        virtual bool IsLoad() const override {return m_isLoaded;};
        
        virtual bool operator==(const Texture& other) const override;
    private:
        TextureSpecification m_specification;

        std::string m_path;
        bool m_isLoaded = false;
        uint32_t m_width;
        uint32_t m_height;
        uint32_t m_rendererID;
        GLenum m_internalFormat;
        GLenum m_dataFormat;
    };

} // namespace Azure



#endif