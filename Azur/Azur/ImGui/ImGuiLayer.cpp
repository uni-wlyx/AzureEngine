#include "azphc.h"
#include "ImGuiLayer.h"
#include "Azur/Core/Application.h"

namespace Azur {
    ImGuiLayer::ImGuiLayer() {

    }

    ImGuiLayer::~ImGuiLayer() {

    }

    void ImGuiLayer::OnAttach() {
        ImGui::CreateContext();
        ImGui::StyleColorsLight();

        ImGuiIO &io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        Application &app = Application::Get();
//        ImGui_ImplGlfw_InitForOpenGL(app.GetWindow(), true);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach() {
        Layer::OnDetach();
    }

    void ImGuiLayer::OnUpdate() {

        ImGuiIO &io = ImGui::GetIO();
        Application &app = Application::Get();
        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

//        static bool show = true;
        ImGui::ShowDemoWindow();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnEvent(Event &event) {
        Layer::OnEvent(event);
    }

} // Azur