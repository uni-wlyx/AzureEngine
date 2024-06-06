
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

        void OnEvent(Event &event);

        void PushLayer(Layer *layer);

        void PushOverlay(Layer *overlay);

        inline static Application &Get() { return *s_instance; }

        inline Window &GetWindow() const { return *m_window; }

    public:
        static Application *CreateApp();

    private:
        std::unique_ptr<Window> m_window;
        LayerStack m_layerStack;

        bool m_running = true;

        bool OnWindowClose(WindowCloseEvent &e);

    private:
        static Application *s_instance;
    };

}


#endif //APPLICATION_H
