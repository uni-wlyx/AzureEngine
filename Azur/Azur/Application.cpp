
#include "Application.h"
Azur::Application::Application() {

}

Azur::Application::~Application() {

}

void Azur::Application::Run() {
    while (true) {}
}

Azur::Application *Azur::Application::CreateApp() {
    return new Application();
}
