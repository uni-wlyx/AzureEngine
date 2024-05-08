
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Azur/Core.h"
#include "Azur/Window/Window.h"
#include "Azur/Events/ApplicationEvent.h"
#include "Azur/Core/LayerStack.h"

namespace Azur {
    class AZUR_API Application {
    public:
        Application();

        virtual ~Application();

        void Run();
        void OnEvent(Event& event);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

    public:
        static Application *CreateApp();

    private:
        std::unique_ptr<Window> m_Window;
        LayerStack m_layerStack;

        bool m_Running = true;

        bool OnWindowClose(WindowCloseEvent& e);
    };

}


#endif //APPLICATION_H
