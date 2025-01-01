#ifndef RENDERER_H
#define RENDERER_H

#pragma once

#include "RenderCommand.h"
#include "RendererAPI.h"
#include "Shader.h"
#include "Azure/Camera/Camera.h"

namespace Azure
{
    class AZURE_API Renderer
    {
    public:
        static void Init();
        static void Shutdown();

        static void BeginScene(Camera &camera);
        static void EndScene();

        static void Submit(const Ref<Shader> &shader, const Ref<VertexArray> &vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

        static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); };

        // static Scope<ShaderLibrary> GetShaderLibrary() { return s_ShaderLibrary; };
        static Scope<ShaderLibrary> s_ShaderLibrary;

    private:
        struct SceneData
        {
            glm::mat4 ViewProjectionMatrix;
        };
        static Scope<SceneData> s_SceneData;
 
    };
} // namespace Azure

#endif