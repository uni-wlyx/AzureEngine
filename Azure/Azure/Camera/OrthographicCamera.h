#ifndef ORTHOGRAPHICCAMERA_H
#define ORTHOGRAPHICCAMERA_H

#pragma once
#include "Camera.h"

namespace Azure
{
    class OrthographicCamera : public Camera
    {
    public:
        explicit OrthographicCamera(glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
                             float yaw = 0,
                             float pitch = 0,float left = -1.0f, float right = 1.0f, float bottom = -1.0f, float top = 1.0f, float zNear = 0.0f, float zFar = 1.0f);

        void SetProjection(float left, float right, float bottom, float top, float zNear, float zFar);

    protected:
        virtual void UpDateProjectionMatrix() override;

    private:
        float m_left;
        float m_right;
        float m_bottom;
        float m_top;
        float m_zNear;
        float m_zFar;
    };

} // namespace Azure

#endif