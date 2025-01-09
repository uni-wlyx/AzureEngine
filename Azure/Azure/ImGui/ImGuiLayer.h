
#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#include "Azure/Core/Layer.h"
#include "Azure/Events/MouseEvent.h"
#include "Azure/Events/KeyEvent.h"
#include "Azure/Events/ApplicationEvent.h"

#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>

namespace Azure {

    class AZURE_API ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach() override;
        void OnDetach() override;

		void BlockEvents(bool block) { m_blockEvents = block; }

        void Begin();
        void End();

        ImGuiContext* GetContext() const { return m_context; }
	private:
		bool m_blockEvents = true;

        ImGuiContext* m_context = nullptr;
    };

} // Azure

#endif //IMGUILAYER_H
