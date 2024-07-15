#ifndef RENDERER_H
#define RENDERER_H

#pragma once

namespace Azure
{
    enum class ERendererAPI
    {
        None = 0,
        OpenGL
    };

    class Renderer
    {
    public:
        inline static ERendererAPI GetAPI() { return s_RenderAPI; };

    private:
        static ERendererAPI s_RenderAPI;
    };
} // namespace Azure

#endif