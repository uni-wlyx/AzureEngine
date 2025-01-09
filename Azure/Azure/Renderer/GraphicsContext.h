
#ifndef GRAPHICSCONTEXT_H
#define GRAPHICSCONTEXT_H

namespace Azure
{

    class GraphicsContext
    {
    public:
        static Ref<GraphicsContext> Create();

        virtual void Init(const void *window) = 0;

        virtual void ShutDown() {};

        virtual void SwapBuffers() = 0;
    };
}

#endif // GRAPHICSCONTEXT_H
