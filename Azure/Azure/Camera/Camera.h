#ifndef CAMERA_H
#define CAMERA_H

#pragma once

#include <glm/glm.hpp>

namespace Azure {
    enum class ECameraType {
        Orthographic, //正交
        Perspective, //透视
    };

    class AZURE_API Camera {
    public:

        /// @brief 
        /// @param postion 
        /// @param rotation 
        /// @return 
        static Camera CreateOrthographic(glm::vec3 postion = glm::vec3(0.0f, 0.0f, 0.0f),
                                         glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f));

        /// @brief 
        /// @param postion 
        /// @param rotation 
        /// @return 
        static Camera CreatePerspective(glm::vec3 postion = glm::vec3(0.0f, 0.0f, 0.0f),
                                        glm::vec3 rotation = glm::vec3(0.0f, -90.0f, 0.0f));

        Camera() = default;

        Camera(ECameraType cameraType, glm::vec3 postion = glm::vec3(0.0f, 0.0f, 0.0f),
               glm::vec3 rotation = glm::vec3(0.0f, -90.0f, 0.0f));

        void OnUpdate(float deltaTime);

        const glm::vec3 &GetPosition() const { return m_position; }

        void SetPosition(const glm::vec3 &position) {
            m_position = position;
            UpDateViewMatrix();
        }

        const glm::vec3 GetRotation() const { return glm::vec3(m_roll, m_yaw, m_pitch); }

        void SetRotation(const glm::vec3 &rotation) {
            m_roll = rotation.x;
            m_yaw = rotation.y;
            m_pitch = rotation.z;
            UpDateViewMatrix();
        }

        const glm::mat4 &GetProjectionMatrix() const { return m_projectionMatrix; }

        const glm::mat4 &GetViewMatrix() const { return m_viewMatrix; }

        const glm::mat4 &GetViewProjectionMatrix() const { return m_viewProjectionMatrix; }

        ECameraType CameraType() const { return m_cameraType; }

        void SetCameraType(ECameraType cameraType);

        void SetProjection(float orthographicSize, float znear, float zfar);

        void SetProjection(float fov, float aspect, float znear, float zfar);


        glm::vec3 GetUpDirection() const;
		glm::vec3 GetRightDirection() const;
		glm::vec3 GetForwardDirection() const;
		const glm::vec3& GetPosition() const { return m_position; }
		glm::quat GetOrientation() const;

    protected:
        virtual void UpDateViewMatrix();

        void UpdateOrthographicView();

        void UpdatePerspectiveView();

        virtual void UpDateProjectionMatrix() {};

        glm::vec3 CalculatePosition() const;
    protected:
        ECameraType m_cameraType;

        float m_moveSpeed = 10;
        float m_sensitivity = 0.1f;
        bool bFirstMouse = true;
        float m_lastX = 0;
        float m_lastY = 0;

        glm::mat4 m_projectionMatrix;
        glm::mat4 m_viewMatrix;
        glm::mat4 m_viewProjectionMatrix;

        glm::vec3 m_position = {0.0f, 0.0f, 0.0f};
        glm::vec3 m_up = {0.0f, 1.0f, 0.0f};

        float m_roll = 0.0f;//x
        float m_yaw = -90.0f;//y
        float m_pitch = 0.0f;//z
        // glm::vec3 m_scale; // 大小应该没有

        //正交
    protected:
        float mo_orthographicSize = 10.0f;
        float mo_zNear = -1.0f;
        float mo_zFar = 1.0f;

        //透视
    protected:
        glm::vec3 m_front = glm::vec3(0.0f, 0.0f, -1.0f);;
        glm::vec3 m_right = glm::vec3(0.0f);
        glm::vec3 m_worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

        float m_fov = 60.0f;
        float m_aspect = (float) 16 / 9;
        float m_znear = 0.1f;
        float m_zfar = 100.0f;

    };
} // namespace Azure

#endif