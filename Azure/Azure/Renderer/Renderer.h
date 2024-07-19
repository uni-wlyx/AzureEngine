#ifndef RENDERER_H
#define RENDERER_H

#pragma once

#include "RenderCommand.h"
#include "RendererAPI.h"
#include "Shader.h"

namespace Azure
{
    class Renderer
    {
    public:
        static void BeginScene();
        static void EndScene();

        static void Submit(const Ref<Shader> &shader, const Ref<VertexArray> &vertexArray);

        static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); };
    };
} // namespace Azure

#endif