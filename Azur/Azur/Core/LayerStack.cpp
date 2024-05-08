
#include "LayerStack.h"

namespace Azur {
    LayerStack::LayerStack() {
        m_layerInsert = m_layers.begin();
    }

    LayerStack::~LayerStack() {
        for (auto layer: m_layers)
            delete layer;
    }

    void LayerStack::PushLayer(Layer *layer) {
        //头插
        m_layerInsert = m_layers.emplace(m_layerInsert, layer);
    }

    void LayerStack::PushOverlay(Layer *overlay) {
        //尾插(优先级更高)
        m_layers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer *layer) {
        auto iter = std::find(m_layers.begin(), m_layers.end(), layer);
        if (iter != m_layers.end()) {
            m_layers.erase(iter);
            m_layerInsert--;
        }
    }

    void LayerStack::PopOverlay(Layer *overlay) {
        auto iter = std::find(m_layers.begin(), m_layers.end(), overlay);
        if (iter != m_layers.end()) {
            m_layers.erase(iter);
        }
    }
} // Azur