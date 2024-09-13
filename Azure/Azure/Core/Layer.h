
#ifndef LAYER_H
#define LAYER_H

#include "Azure/Core.h"
#include "Azure/Events/Event.h"

struct ImGuiContext;

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

        /// @brief 如果在dll外使用，调用SetCurrentContext
        /// @param context 
        virtual void OnImGuiRender(ImGuiContext * context) {};

        virtual void OnUpdate(float deltaTime) {}

        virtual void OnEvent(Event &event) {}
    };

}


#endif //LAYER_H
