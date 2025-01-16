#include "azpch.h"
#include "Camera.h"
#include "Azure/Core/Input.h"
#include "Azure/Core/KeyCodes.h"
#include "Azure/Core/MouseCodes.h"
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
        m_roll = rotation.x;
        m_yaw = rotation.y;
        m_pitch = rotation.z;

        SetCameraType(cameraType);
        // m_cameraType = cameraType;

        // UpDateViewMatrix();
        // if (cameraType == ECameraType::Orthographic)
        // {
        //     SetProjection(mo_left, mo_right, mo_top, mo_bottom, mo_zNear, mo_zFar);
        // }
        // else if (cameraType == ECameraType::Perspective)
        // {
        //     SetProjection(m_fov, m_aspect, m_znear, m_zfar);
        // }
    }

    void Camera::OnUpdate(float deltaTime)
    {
        float velocity = m_moveSpeed * deltaTime;
        if(Input::IsKeyPressed(Key::W))  
            m_position +=m_front * velocity;
        if(Input::IsKeyPressed(Key::S))  m_position -=m_front * velocity;
        if(Input::IsKeyPressed(Key::A))  m_position -=m_right * velocity;
        if(Input::IsKeyPressed(Key::D))  m_position +=m_right * velocity;

        if(Input::IsMouseButtonPressed(Mouse::ButtonRight))
        {
            auto [xpos,ypos] = Input::GetMousePosition();

            if(bFirstMouse)
            {
                m_lastX = xpos;
                m_lastY = ypos;
                bFirstMouse = false;
            }

            float xoffset = xpos - m_lastX;
            float yoffset = m_lastY - ypos;
            m_lastX = xpos;
            m_lastY = ypos;

            xoffset *=m_sensitivity;
            yoffset *= m_sensitivity;

            m_yaw   += xoffset;
            m_pitch += yoffset;

            m_pitch = glm::clamp(m_pitch,-89.0f,89.0f);

        }else
        {
             bFirstMouse = true;
        }

        UpDateViewMatrix();
    }

    void Camera::SetCameraType(ECameraType cameraType)
    {
        m_cameraType = cameraType; 
        UpDateViewMatrix(); 

        if (cameraType == ECameraType::Orthographic)
        {
            SetProjection(mo_orthographicSize, mo_zNear, mo_zFar);
        }
        else if (cameraType == ECameraType::Perspective)
        {
            SetProjection(m_fov, m_aspect, m_znear, m_zfar);
        }
    }


    void Camera::SetProjection(float orthographicSize, float znear, float zfar)
    {

        mo_orthographicSize = orthographicSize;
        float oleft = -mo_orthographicSize * m_aspect * 0.5f;
        float oright = mo_orthographicSize * m_aspect * 0.5f;
        float otop = -mo_orthographicSize * 0.5f;
        float obottom = mo_orthographicSize * 0.5f;;
        mo_zNear = znear;
        mo_zFar = zfar;

        m_projectionMatrix = (glm::ortho(oleft, oright, obottom, otop, mo_zNear, mo_zFar));
        m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
    }

    void Camera::SetProjection(float fov, float aspect, float znear, float zfar)
    {

        m_fov = fov;
        // m_fov = 45;
        m_aspect = aspect;
        m_znear = znear;
        m_zfar = zfar;
        // m_zfar = 100;

        m_projectionMatrix = glm::perspective(glm::radians(m_fov), m_aspect,m_znear,m_zfar);             
        

        // auto xx = glm::perspective(
        //     glm::radians(m_fov), // fov
        //     m_aspect,            // 宽高比 (屏占比)
        //     m_znear,             // 最近可视距离
        //     m_zfar);             // 最远可视距离
        // ;
        m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
    }

    glm::vec3 Camera::GetUpDirection() const
    {
       return glm::rotate(GetOrientation(), glm::vec3(0.0f, 1.0f, 0.0f));
    }

    glm::vec3 Camera::GetRightDirection() const
    {
        return glm::rotate(GetOrientation(), glm::vec3(1.0f, 0.0f, 0.0f));
    }

    glm::vec3 Camera::GetForwardDirection() const
    {
        return glm::rotate(GetOrientation(), glm::vec3(0.0f, 0.0f, -1.0f));
    }

    glm::quat Camera::GetOrientation() const
    {
        return glm::quat(glm::vec3(-m_pitch, -m_yaw, 0.0f));
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

        auto orientation = glm::quat(glm::vec3(-m_pitch, -m_yaw, 0.0f));
        m_viewMatrix = glm::translate(glm::mat4(1.0f), m_position) * glm::toMat4(orientation);
		m_viewMatrix = glm::inverse(m_viewMatrix);

        // glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_position) *
                            //   glm::rotate(glm::mat4(1.0f), glm::radians(m_roll), glm::vec3(0, 0, 1));
        // m_viewMatrix = glm::inverse(transform);
    }

    void Camera::UpdatePerspectiveView()
    {
        // glm::vec3 front;

        // front.x = glm::cos(glm::radians(m_yaw)) * glm::cos(glm::radians(m_pitch));
        // front.y = glm::sin(glm::radians(m_pitch));
        // front.z = glm::sin(glm::radians(m_yaw)) * glm::cos(glm::radians(m_pitch));
        // m_front = glm::normalize(front);

        // m_right = glm::normalize(glm::cross(front, m_worldUp));
        // m_up = glm::normalize(glm::cross(m_right, front));

        // m_viewMatrix = glm::lookAt(m_position, m_position + m_front, m_up);

        m_position = CalculatePosition();

		// glm::quat orientation = GetOrientation();
		// mViewMatrix = glm::translate(glm::mat4(1.0f), mPosition) * glm::toMat4(orientation);
		// mViewMatrix = glm::inverse(mViewMatrix);

    }

    glm::vec3 Camera::CalculatePosition() const
    {
        // return mFocalPoint - GetForwardDirection() * mDistance;
    }

} // namespace Azure
