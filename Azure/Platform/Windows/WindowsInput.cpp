#include "azpch.h"
#include "WindowsInput.h"
#include "Azure/Core/Application.h"

#include "SDL.h"

namespace Azure {
    Input *Input::s_Instance = new WindowsInput();

    bool WindowsInput::IsKeyPressedImpl(int keycode) {
        SDL_PumpEvents();
        const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
        return keyboardState[keycode] == SDL_PRESSED;


        // auto Windows = static_cast<GLFWwindow *> (Application::Get().GetWindow().GetNativeWindow());
        // auto state = glfwGetKey(Windows, keycode);
        // return state == GLFW_PRESS || state == GLFW_REPEAT;
        // return false;
    }

    bool WindowsInput::IsKeyReleasedImpl(int keycode) {
        SDL_PumpEvents();
        const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
        return keyboardState[keycode] == SDL_RELEASED;

    //     auto Windows = static_cast<GLFWwindow *> (Application::Get().GetWindow().GetNativeWindow());
    //     auto state = glfwGetKey(Windows, keycode);
    //     return state == GLFW_RELEASE;
                // return false;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(int button) {
        SDL_PumpEvents();
        uint32_t mouseButton = SDL_GetMouseState(0, 0);
        return  (SDL_BUTTON(button) & mouseButton)!=0 ;

        // auto Windows = static_cast<GLFWwindow *> (Application::Get().GetWindow().GetNativeWindow());
        // auto state = glfwGetMouseButton(Windows, button);
                // return false;
    }

    float WindowsInput::GetMouseXImpl() {
        return (float) GetMousePositionImpl().first;
    }

    float WindowsInput::GetMouseYImpl() {
        return (float) GetMousePositionImpl().second;
    }

    std::pair<float, float> WindowsInput::GetMousePositionImpl() {
        int xpos, ypos;
        SDL_GetMouseState(&xpos,&ypos);
        return {(float) xpos, (float) ypos};
    }
} // Azure