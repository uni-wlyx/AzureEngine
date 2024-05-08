
#include "Application.h"
#include "Azur/Log/AzurLog.h"

namespace Azur {
    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(AZ_BIND_EVENT(Application::OnEvent));
    }

    Application::~Application() {

    }

    void Application::Run() {
        while (m_Running) {
            m_Window->OnUpdate();
        }
    }

    Application *Azur::Application::CreateApp() {
        return new Application();
    }

    void Application::OnEvent(Azur::Event &event) {
        AZ_CORE_INFO(event.ToString());
        EventDispatcher dispatcher(event);

        dispatcher.Dispatch<WindowCloseEvent>(AZ_BIND_EVENT(Application::OnWindowClose));
    }

    bool Application::OnWindowClose(WindowCloseEvent &e) {
        m_Running = false;
        return true;
    }
}

