#include <iostream>
#include <Azur.h>

int main() {

    auto *app = Azur::Application::CreateApp();
    app->Run();
    delete app;

    return 0;
}
