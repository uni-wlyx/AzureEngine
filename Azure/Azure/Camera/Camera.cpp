#include "azpch.h"
#include "Camera.h"

#include <glm/gtx/quaternion.hpp>

namespace Azure
{
    void Camera::UpDateViewMatrix()
    {
        glm::vec3 front;

        front.x = glm::cos(glm::radians(m_yaw)) * glm::cos(glm::radians(m_pitch));
        front.y = glm::sin(glm::radians(m_pitch));
        front.z = glm::sin(glm::radians(m_yaw)) * glm::cos(glm::radians(m_pitch));
        m_front = glm::normalize(front);

        m_right = glm::normalize(glm::cross(front,m_worldUp));
        m_up = glm::normalize(glm::cross(m_right,front));

        m_viewMatrix = glm::lookAt(m_position,m_position + m_front,m_up);

        m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
    }

} // namespace Azure
