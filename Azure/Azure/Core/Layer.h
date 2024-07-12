
#ifndef LAYER_H
#define LAYER_H

#include "Azure/Core.h"
#include "Azure/Events/Event.h"

namespace Azure {
    /**
     * 层
     */
    class AZURE_API Layer {
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
