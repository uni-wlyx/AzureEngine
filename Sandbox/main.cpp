#include <iostream>
#include <Azur.h>

int main() {

    Azur::AzurLog::Init();
    AZ_CORE_INFO("init");
    auto *app = Azur::Application::CreateApp();
    app->Run();
    delete app;

    return 0;
}
