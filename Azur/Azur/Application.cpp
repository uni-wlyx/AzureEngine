#include "Application.h"

Azur::Application::Application() {
    m_Window = std::unique_ptr<Window>(Window::Create());
}

Azur::Application::~Application() {

}

void Azur::Application::Run() {
    while (m_Running) {
        m_Window->OnUpdate();
    }
}

Azur::Application *Azur::Application::CreateApp() {
    return new Application();
}
