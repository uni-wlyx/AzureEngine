
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Azure/Core.h"
#include "Azure/Window/Window.h"
#include "Azure/Events/ApplicationEvent.h"
#include "Azure/Core/LayerStack.h"

#include "Azure/ImGui/ImGuiLayer.h"

#include "Azure/Renderer/Shader.h"
#include "Azure/Renderer/Buffer.h"


namespace Azure {

    // static GLenum ShaderDataTypeToOpenGLBaseType(EShaderDataType type)
    // {
    //     switch (type)
    //     {
    //         case EShaderDataType::Float:    return GL_FLOAT;
    //         case EShaderDataType::Float2:    return GL_FLOAT;
    //         case EShaderDataType::Float3:    return GL_FLOAT;
    //         case EShaderDataType::Float4:    return GL_FLOAT;
    //         case EShaderDataType::Mat3:    return GL_FLOAT;
    //         case EShaderDataType::Mat4:    return GL_FLOAT;
    //         case EShaderDataType::Int:    return GL_INT;
    //         case EShaderDataType::Int2:    return GL_INT;
    //         case EShaderDataType::Int3:    return GL_INT;
    //         case EShaderDataType::Int4:    return GL_INT;
    //         case EShaderDataType::Bool:    return GL_BOOL;
    //     }
    //     AZ_CORE_ASSERT(false, "Unknown ShaderDataType!");
    //     return 0;
    // };

    class AZURE_API Application {
    public:
        Application();

        virtual ~Application();

        void Run();

        void OnEvent(Event &event);

        void PushLayer(Layer *layer);

        void PushOverlay(Layer *overlay);

        inline static Application &Get() { return *s_instance; }

        inline Window &GetWindow() const { return *m_window; }

    public:
        static Application *CreateApp();

    private:
        Scope <Window> m_window;
        ImGuiLayer *m_ImGuiLayer;
        LayerStack m_layerStack;

        bool m_running = true;

        bool OnWindowClose(WindowCloseEvent &e);

    private:
        static Application *s_instance;

        uint32_t m_VertexArray,m_VertexBuffer,m_IndexBuffer;
        Scope<Shader> m_shader;
    };

}


#endif //APPLICATION_H
