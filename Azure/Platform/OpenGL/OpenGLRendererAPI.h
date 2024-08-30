#ifndef OPENGLRENDERERAPI_H
#define OPENGLRENDERERAPI_H

#pragma once

#include "Azure/Renderer/RendererAPI.h"

namespace Azure
{
    class OpenGLRendererAPI : public RendererAPI
    {
    public:
        virtual void SetClearColor(const glm::vec4 &color) override;
        virtual void Clear() override;

        virtual void DrawIndexed(const Ref<VertexArray> &vertexArray) override;
        virtual void ResizeViewport(int width, int height) override;

    private:
    };
}

#endif