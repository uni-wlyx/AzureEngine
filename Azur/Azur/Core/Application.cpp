
#include "Application.h"
#include "Azur/Log/AzurLog.h"

namespace Azur {
    Application *Application::s_instance = nullptr;

    Application::Application() {
        AZ_CORE_ASSERT(!s_instance, "Application already exists");
        s_instance = this;

        m_window = std::unique_ptr<Window>(Window::Create());
        m_window->SetEventCallback(AZ_BIND_EVENT(Application::OnEvent));
    }

    Application::~Application() {

    }

    void Application::Run() {
        while (m_running) {

            for (Layer *layer: m_layerStack) {
                layer->OnUpdate();
            }

            m_window->OnUpdate();
        }
    }

    void Application::PushLayer(Layer *layer) {
        m_layerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *overlay) {
        m_layerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }

    Application *Azur::Application::CreateApp() {
        return new Application();
    }

    void Application::OnEvent(Azur::Event &event) {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(AZ_BIND_EVENT(Application::OnWindowClose));

        for (auto iter = m_layerStack.end(); iter != m_layerStack.begin();) {
            (*--iter)->OnEvent(event);
            if (event.Handled) {
                break;//当事件被处理，不用传递下去
            }
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e) {
        m_running = false;
        return true;
    }


}

