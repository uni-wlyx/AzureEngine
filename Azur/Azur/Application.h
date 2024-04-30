
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"

namespace Azur {
    class AZUR_API Application {
    public:
        Application();

        virtual ~Application();

        void Run();

    public:
        static Application *CreateApp();
    };

}


#endif //APPLICATION_H
