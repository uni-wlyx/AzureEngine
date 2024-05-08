
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

            for(Layer* layer:m_layerStack){
                layer->OnUpdate();
            }

            m_Window->OnUpdate();
        }
    }

    void Application::PushLayer(Layer *layer) {
        m_layerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer *overlay) {
        m_layerStack.PushOverlay(overlay);
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
        m_Running = false;
        return true;
    }


}

