#ifndef EDITORLAYER_H
#define EDITORLAYER_H

#pragma once

#include "Azure.h"

namespace Azure
{
    class AZURE_API EditorLayer : public Layer
    {
    public:
        EditorLayer();

        virtual void OnUpdate(float deltaTime) override;

        virtual void OnImGuiRender(ImGuiContext *context) override;

        virtual void OnEvent(Azure::Event &event) override;

    public:
        float xp = 0;
        float spp = 0;

        glm::vec3 pos = {-3, 0, 0};
        glm::mat4 model = glm::mat4(1);

    private:
        Camera m_camera;
        Ref<VertexArray> m_vertexArray;
        Ref<Shader> m_shader;
        Ref<Texture> m_texture;
    };
}

#endif