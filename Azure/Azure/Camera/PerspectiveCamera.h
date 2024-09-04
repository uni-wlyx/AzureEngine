#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#pragma once

#include "Camera.h"

namespace Azure
{
    class PerspectiveCamera//:public Camera
    {
    public:
        explicit PerspectiveCamera(glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f),glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
                        float yaw = 0,
                        float pitch = 0,float fov = 60,float aspect = 16/9,float zfar = 100);
    private:
        float m_fov;
        float m_aspect;
        float m_zfar;
    };
}

#endif