#include <iostream>
#include <Azure.h>


class ExampleLayer : public Azure::Layer {
public:
    void OnUpdate() override {
//        AZ_INFO("ExampleLayer::Layer");
    }

    void OnEvent(Azure::Event &event) override {

    }
};

int main() {
    Azure::AzureLog::Init();

    AZ_CORE_INFO("Init Log");

    auto *app = Azure::Application::CreateApp();
//    app->PushLayer(new ExampleLayer());
//    app->PushOverlay(new Azure::ImGuiLayer());
    app->Run();
    delete app;

    return 0;
}
