#ifndef RENDERER_H
#define RENDERER_H

#pragma once

#include "RenderCommand.h"
#include "RendererAPI.h"
#include "Shader.h"
#include "Azure/Camera/Camera.h"

namespace Azure
{
    class Renderer
    {
    public:
        static void BeginScene(Camera &camera);
        static void EndScene();

        static void Submit(const Ref<Shader> &shader, const Ref<VertexArray> &vertexArray);

        static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); };

    private:
        struct SceneData
        {
            glm::mat4 ViewProjectionMatrix;
        };
        static Scope<SceneData> s_SceneData;
    };
} // namespace Azure

#endif