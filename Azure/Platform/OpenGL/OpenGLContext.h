
#ifndef OPENGLCONTEXT_H
#define OPENGLCONTEXT_H

#include "Azure/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Azure {
    class OpenGLContext : public GraphicsContext {
    public:
        OpenGLContext(GLFWwindow *windowHandle);

        void Init() override;

        void SwapBuffers() override;

    private:
        GLFWwindow* m_windowHandle;
    };
}


#endif //OPENGLCONTEXT_H
