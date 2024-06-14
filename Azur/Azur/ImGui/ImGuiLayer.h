
#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#include "Azur/Core/Layer.h"
#include "Azur/Events/MouseEvent.h"
#include "Azur/Events/KeyEvent.h"
#include "Azur/Events/ApplicationEvent.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Azur {

    class AZUR_API ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Azur::Event &event) override;
    private:
        float m_time = 0.0f;

        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
//        void OnKeyTypedEvent(KeyTypedEvent& e);
        bool OnWindowResizedEvent(WindowResizeEvent& e);
    };

} // Azur

#endif //IMGUILAYER_H
