#include "azpch.h"
#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Azure
{
    OrthographicCamera::OrthographicCamera(glm::vec3 pos, glm::vec3 up,
                                           float yaw,
                                           float pitch, float left, float right, float bottom, float top, float zNear, float zFar)
    {
        m_position = pos;
        m_worldUp = up;
        m_yaw = yaw;
        m_pitch = pitch;
        
        m_viewMatrix = glm::mat4(1.0f);
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_position) *
			glm::rotate(glm::mat4(1.0f), glm::radians(m_roll), glm::vec3(0, 0, 1));
		m_viewMatrix = glm::inverse(transform);

        // UpDateViewMatrix();
        SetProjection(left, right, bottom, top, zNear, zFar);
    }

    void OrthographicCamera::SetProjection(float left, float right, float bottom, float top, float zNear, float zFar)
    {
        m_left = left;
        m_right = right;
        m_bottom = bottom;
        m_top = top;
        m_zNear = zNear;
        m_zFar = zFar;

        UpDateProjectionMatrix();
    }

    void OrthographicCamera::UpDateProjectionMatrix()
    {
        m_projectionMatrix = glm::ortho(m_left, m_right, m_bottom, m_top, m_zNear, m_zFar);
        m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
    }

} // namespace Azure