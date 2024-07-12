
#ifndef WINDOWSINPUT_H
#define WINDOWSINPUT_H

#include "Azur/Core/Input.h"

namespace Azure {

    class WindowsInput : public Input {
    protected:
        bool IsKeyPressedImpl(int keycode) override;

        bool IsKeyReleasedImpl(int keycode) override;

        bool IsMouseButtonPressedImpl(int button) override;

        std::pair<float, float> GetMousePositionImpl() override;

        float GetMouseXImpl() override;

        float GetMouseYImpl() override;
    };

} // Azur

#endif //WINDOWSINPUT_H
