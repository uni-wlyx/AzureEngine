
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Azur/Core.h"
#include "Azur/Window/Window.h"

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
    };

}


#endif //APPLICATION_H
