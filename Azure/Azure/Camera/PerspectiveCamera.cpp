#include "azpch.h"
#include "PerspectiveCamera.h"

namespace Azure
{
    PerspectiveCamera::PerspectiveCamera(glm::vec3 pos, glm::vec3 up, float yaw, float pitch, float fov, float aspect, float zfar)
    {
        m_position = pos;
        m_worldUp = up;
        m_yaw = yaw;
        m_pitch = pitch;
        m_fov = fov;
        m_aspect = aspect;
        m_zfar = zfar;
        UpDateViewMatrix();
    }

}
