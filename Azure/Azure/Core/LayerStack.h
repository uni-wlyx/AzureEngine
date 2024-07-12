
#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include "Layer.h"

namespace Azure {

    class AZURE_API LayerStack {
    public:
        LayerStack();

        ~LayerStack();

        void PushLayer(Layer *layer);

        void PushOverlay(Layer *overlay);

        void PopLayer(Layer *layer);

        void PopOverlay(Layer *overlay);

        std::vector<Layer *>::iterator begin() { return m_layers.begin(); }

        std::vector<Layer *>::iterator end() { return m_layers.end(); }

    private:
        std::vector<Layer *> m_layers;
        unsigned int m_layerInsertIndex = 0;
    };

} // Azure

#endif //LAYERSTACK_H
