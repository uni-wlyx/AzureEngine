
#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#include "Azur/Core/Layer.h"

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
    };

} // Azur

#endif //IMGUILAYER_H
