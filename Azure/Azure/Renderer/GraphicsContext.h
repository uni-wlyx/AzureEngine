
#ifndef GRAPHICSCONTEXT_H
#define GRAPHICSCONTEXT_H

namespace Azure {
    class GraphicsContext {
    public:
        GraphicsContext() {};

        virtual ~GraphicsContext() = default;

        virtual void Init() = 0;

        virtual void SwapBuffers() = 0;
    };
}

#endif //GRAPHICSCONTEXT_H
