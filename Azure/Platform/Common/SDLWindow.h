#ifndef SDLWINDOW_H
#define SDLWINDOW_H

#pragma once

#include "Azure/Window/Window.h"
#include "Azure/Renderer/GraphicsContext.h"

#include <SDL.h>

namespace Azure
{
    class SDLWindow : public Window
    {
    public:
        explicit SDLWindow();

        ~SDLWindow() override;

        void OnUpdate() override;

        unsigned int GetWidth() const override { return m_data.Width; };

        unsigned int GetHeight() const override { return m_data.Height; };

        void SetEventCallback(const EventCallbackFn &callback) override { m_data.EventCallback = callback; }

        void *GetNativeWindow() const override;

        void Init(const WindowProps &props = WindowProps()) override;

        void ShutDown() override;

    private:
        SDL_Window* m_window;
        SDL_Event sdlEvent;
        Ref <GraphicsContext> m_context;

        struct WindowData {
            std::string Title;
            unsigned int Width, Height;

            EventCallbackFn EventCallback;
        };

        WindowData m_data;
        
    };
}

#endif