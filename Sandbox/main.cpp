#include <iostream>
#include <Azur.h>


class ExampleLayer : public Azur::Layer{
public:
    void OnUpdate() override{
//        AZ_INFO("ExampleLayer::Layer");
    }

    void OnEvent(Azur::Event &event) override{
        AZ_INFO("ExampleLayer::OnEvent");
    }
};

int main() {
    Azur::AzurLog::Init();
    AZ_CORE_INFO("Init Log");

    auto *app = Azur::Application::CreateApp();
    app->PushLayer(new ExampleLayer());
    app->Run();
    delete app;

    return 0;
}
