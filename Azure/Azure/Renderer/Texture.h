#ifndef TEXTURE_H
#define TEXTURE_H

#pragma once

namespace Azure
{
    enum class ImageFormat
    {
        None = 0,
        R8,
        RGB8,
        RGBA8,
        RGBA32F,
    };

    struct TextureSpecification
    {
        uint32_t Width = 1;
        uint32_t Height = 1;
        ImageFormat Format = ImageFormat::RGBA8;
        bool GenerateMips = true;
    };

    class AZURE_API Texture
    {
    public:
        virtual ~Texture() = default;

        virtual const TextureSpecification& GetSpecification() const = 0;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;
        virtual uint32_t GetRendererID() const = 0;

        virtual const std::string& GetPath() const = 0;

        virtual void SetData(void* data,uint32_t size) = 0;
        virtual void Bind(uint32_t slot = 0) const = 0;
        virtual bool IsLoad() const = 0;
        
        virtual bool operator==(const Texture& other) const = 0;
    };

    class AZURE_API Texture2D : public Texture
    {
    public:
		static Ref<Texture2D> Create(const TextureSpecification& specification);
		static Ref<Texture2D> Create(const std::string& path);
    };

    class AZURE_API Texture3D : public Texture
    {
    public:
		static Ref<Texture2D> Create(const TextureSpecification& specification);
		static Ref<Texture2D> Create(const std::string& path);
    };

} // namespace Azure

#endif