
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

        void OnImGuiRender() override;

        void Begin();
        void End();
    private:
        float m_time = 0.0f;
    };

} // Azur

#endif //IMGUILAYER_H
