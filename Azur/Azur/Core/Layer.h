
#ifndef LAYER_H
#define LAYER_H

#include "Azur/Core.h"
#include "Azur/Events/Event.h"

namespace Azur {
    /**
     * 层
     */
    class AZUR_API Layer {
    public:
        Layer() = default;

        virtual ~Layer() = default;

        virtual void OnAttach() {}

        virtual void OnDetach() {}

        virtual void OnImGuiRender() {};

        virtual void OnUpdate() {}

        virtual void OnEvent(Event &event) {}
    };

}


#endif //LAYER_H
