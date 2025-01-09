#ifndef OPENGLCONTEXT_H
#define OPENGLCONTEXT_H

#pragma once

#include "Azure/Renderer/GraphicsContext.h"

struct SDL_Window;

namespace Azure {
    class OpenGLContext : public GraphicsContext {
    public:
        void Init(const void * window) override;

        void ShutDown() override;

        void SwapBuffers() override;

    private:
        SDL_Window* m_windowHandle;
        void * m_context;

    };
}


#endif //OPENGLCONTEXT_H
