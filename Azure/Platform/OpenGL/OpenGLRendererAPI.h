#ifndef OPENGLRENDERERAPI_H
#define OPENGLRENDERERAPI_H

#pragma once

#include "Azure/Renderer/RendererAPI.h"

namespace Azure
{
    class OpenGLRendererAPI : public RendererAPI
    {
    public:
        void Init() override;
        void SetClearColor(const glm::vec4 &color) override;
        void Clear() override;

        void DrawIndexed(const Ref<VertexArray> &vertexArray) override;
        void SetViewport(int width, int height) override;

    private:
    };
}

#endif