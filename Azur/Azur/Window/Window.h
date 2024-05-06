
#ifndef WINDOW_H
#define WINDOW_H

#include "azphc.h"

#include "Azur/Core.h"
//#include <>

namespace Azur {

    struct WindowProps {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        explicit WindowProps(const std::string &title = "Azur Engine", unsigned int width = 1280,
                             unsigned int height = 720)
                : Title(title), Width(width), Height(height) {

        }
    };

    class AZUR_API Window {
    public:
        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;

        virtual unsigned int GetHeight() const = 0;

        static Window *Create(const WindowProps &props = WindowProps());
    };
}


#endif //WINDOW_H
