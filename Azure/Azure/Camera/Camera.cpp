#include "azpch.h"
#include "Camera.h"

#include <glm/gtx/quaternion.hpp>

namespace Azure
{
    Camera Camera::CreateOrthographic(glm::vec3 postion, glm::vec3 rotation)
    {
        return Camera(ECameraType::Orthographic, postion, rotation);
    }

    Camera Camera::CreatePerspective(glm::vec3 postion, glm::vec3 rotation)
    {
        return Camera(ECameraType::Perspective, postion, rotation);
    }

    Camera::Camera(ECameraType cameraType, glm::vec3 postion, glm::vec3 rotation)
    {
        m_position = postion;
        m_pitch = rotation.x;
        m_roll = rotation.y;
        m_yaw = rotation.z;

        m_cameraType = cameraType;

        UpDateViewMatrix();
        if (cameraType == ECameraType::Orthographic)
        {
            SetProjection(mo_left, mo_right, mo_top, mo_bottom, mo_zNear, mo_zFar);
        }
        else if (cameraType == ECameraType::Perspective)
        {
            SetProjection(m_fov, m_aspect, m_znear, m_zfar);
        }
    }

    void Camera::SetProjection(float left, float right, float bottom, float top, float znear, float zfar)
    {
        mo_left = left;
        mo_right = right;
        mo_top = top;
        mo_bottom = bottom;
        mo_zNear = znear;
        mo_zFar = zfar;

        m_projectionMatrix = (glm::ortho(mo_left, mo_right, mo_bottom, mo_top, mo_zNear, mo_zFar));
        m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
    }

    void Camera::SetProjection(float fov, float aspect, float znear, float zfar)
    {

        m_fov = fov;
        m_aspect = aspect;
        m_znear = znear;
        m_zfar = zfar;

        m_projectionMatrix = glm::perspective(glm::radians(m_fov), m_aspect,m_znear,m_zfar);             
        

        // auto xx = glm::perspective(
        //     glm::radians(m_fov), // fov
        //     m_aspect,            // 宽高比 (屏占比)
        //     m_znear,             // 最近可视距离
        //     m_zfar);             // 最远可视距离
        // ;
        m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
    }

    void Camera::UpDateViewMatrix()
    {

        switch (m_cameraType)
        {
        case ECameraType::Orthographic:
        {
            UpdateOrthographicView();
            break;
        }
        case ECameraType::Perspective:
        {
            UpdatePerspectiveView();
            break;
        }
        default:
        {
            AZ_ASSERT(false, "Error CameraType");
            return;
        }
        }

        m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
    }

    void Camera::UpdateOrthographicView()
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_position) *
                              glm::rotate(glm::mat4(1.0f), glm::radians(m_roll), glm::vec3(0, 0, 1));
        m_viewMatrix = glm::inverse(transform);
    }

    void Camera::UpdatePerspectiveView()
    {
        glm::vec3 front;

        front.x = glm::cos(glm::radians(m_yaw)) * glm::cos(glm::radians(m_pitch));
        front.y = glm::sin(glm::radians(m_pitch));
        front.z = glm::sin(glm::radians(m_yaw)) * glm::cos(glm::radians(m_pitch));
        m_front = glm::normalize(front);

        m_right = glm::normalize(glm::cross(front, m_worldUp));
        m_up = glm::normalize(glm::cross(m_right, front));

        m_viewMatrix = glm::lookAt(m_position, m_position + m_front, m_up);
    }

} // namespace Azure
