
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Azure/Core.h"
#include "Azure/Window/Window.h"
#include "Azure/Events/ApplicationEvent.h"
#include "Azure/Core/LayerStack.h"

#include "Azure/ImGui/ImGuiLayer.h"

#include "Azure/Renderer/Shader.h"

namespace Azure {
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
