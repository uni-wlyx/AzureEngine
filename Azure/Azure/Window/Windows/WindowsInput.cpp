#include "azphc.h"
#include "WindowsInput.h"
#include "Azure/Core/Application.h"

#include <GLFW/glfw3.h>

namespace Azure {
    Input *Input::s_Instance = new WindowsInput();

    bool WindowsInput::IsKeyPressedImpl(int keycode) {
        auto Windows = static_cast<GLFWwindow *> (Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(Windows, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::IsKeyReleasedImpl(int keycode) {
        auto Windows = static_cast<GLFWwindow *> (Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(Windows, keycode);
        return state == GLFW_RELEASE;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(int button) {
        auto Windows = static_cast<GLFWwindow *> (Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(Windows, button);
        return state == GLFW_PRESS;
    }

    float WindowsInput::GetMouseXImpl() {
        return (float) GetMousePositionImpl().first;
    }

    float WindowsInput::GetMouseYImpl() {
        return (float) GetMousePositionImpl().second;
    }

    std::pair<float, float> WindowsInput::GetMousePositionImpl() {
        auto Windows = static_cast<GLFWwindow *> (Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(Windows, &xpos, &ypos);
        return {(float) xpos, (float) ypos};
    }
} // Azure