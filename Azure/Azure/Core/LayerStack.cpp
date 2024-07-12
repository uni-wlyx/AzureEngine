
#include "LayerStack.h"

namespace Azure {
    LayerStack::LayerStack() {

    }

    LayerStack::~LayerStack() {
        for (auto layer: m_layers)
            delete layer;
    }

    void LayerStack::PushLayer(Layer *layer) {
        //头插
        m_layers.emplace(m_layers.begin() + m_layerInsertIndex, layer);
        ++m_layerInsertIndex;
    }

    void LayerStack::PushOverlay(Layer *overlay) {
        //尾插(优先级更高)
        m_layers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer *layer) {
        auto iter = std::find(m_layers.begin(), m_layers.end(), layer);
        if (iter != m_layers.end()) {
            m_layers.erase(iter);
            m_layerInsertIndex--;
        }
    }

    void LayerStack::PopOverlay(Layer *overlay) {
        auto iter = std::find(m_layers.begin(), m_layers.end(), overlay);
        if (iter != m_layers.end()) {
            m_layers.erase(iter);
        }
    }
} // Azur