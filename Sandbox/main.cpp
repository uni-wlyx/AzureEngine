#include <iostream>
#include <Azur.h>

class event {

};

class xxevent : public event {
public:
    int x, y;

    xxevent(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    Azur::AzurLog::Init();
    AZ_CORE_INFO("Init Log");

    auto *app = Azur::Application::CreateApp();
    app->Run();
    delete app;

    return 0;
}
