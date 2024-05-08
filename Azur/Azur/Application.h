
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Azur/Core.h"
#include "Azur/Window/Window.h"
#include <Azur/Event/ApplicationEvent.h>

namespace Azur {
    class AZUR_API Application {
    public:
        Application();

        virtual ~Application();

        void Run();

    public:
        static Application *CreateApp();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;

        void OnEvent(Event& event);

        bool OnWindowClose(WindowCloseEvent& e);
    };

}


#endif //APPLICATION_H
