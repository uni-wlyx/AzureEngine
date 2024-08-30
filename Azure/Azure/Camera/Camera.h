#ifndef CAMERA_H
#define CAMERA_H

#pragma once

#include <glm/glm.hpp>

namespace Azure
{
    enum class ECameraType{
        Orthographic, //正交
        Perspective, //透视
    };

    class Camera 
    {
    public:
        /// @brief 
        /// @param pos 
        /// @param up 
        /// @param yaw 
        /// @param pitch 
        /// @param left 
        /// @param right 
        /// @param bottom 
        /// @param top 
        /// @param zNear 
        /// @param zFar 
        /// @return 
        static Camera CreateOrthographic(glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
                             float yaw = 0,
                             float pitch = 0,float left = -1.0f, float right = 1.0f, float bottom = -1.0f, float top = 1.0f, float zNear = 0.0f, float zFar = 1.0f);
        /// @brief 
        /// @param pos 
        /// @param up 
        /// @param yaw 
        /// @param pitch 
        /// @param fov 
        /// @param aspect 
        /// @param zfar 
        /// @return 
        static Camera CreatePerspective(glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f),glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
                        float yaw = 0,
                        float pitch = 0,float fov = 60,float aspect = 16/9,float zfar = 100);

	    const glm::vec3& GetPosition() const { return m_position; }
		void SetPosition(const glm::vec3& position) { m_position = position; UpDateViewMatrix(); }

        const glm::vec3& GetRotation() const { return {m_pitch, m_yaw, m_roll}; }
        void SetRotation(const glm::vec3& rotation) { m_pitch = rotation.x; m_yaw = rotation.y;m_roll = rotation.z; UpDateViewMatrix(); }

		const glm::mat4& GetProjectionMatrix() const { return m_projectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_viewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const { return m_viewProjectionMatrix; }

        ECameraType CameraType() const { return m_cameraType; }
        void SetCameraType(ECameraType cameraType) { m_cameraType = cameraType;};

    protected:
        virtual void UpDateViewMatrix();
        virtual void UpDateProjectionMatrix() {};
    protected:
        ECameraType m_cameraType;

        glm::mat4 m_projectionMatrix;
        glm::mat4 m_viewMatrix;
        glm::mat4 m_viewProjectionMatrix;

        glm::vec3 m_position = {0.0f, 0.0f, 0.0f};
        
        float m_pitch = 0.0f;
        float m_roll  = 0.0f;
        float m_yaw   = 0.0f;
        // glm::vec3 m_scale; // 大小应该没有

    //正交
    protected:
        float mo_left;
        float mo_right;
        float mo_bottom;
        float mo_top;
        float mo_zNear;
        float mo_zFar;

    //透视
    protected:
        glm::vec3 m_front;
        glm::vec3 m_up;
        glm::vec3 m_right;
        glm::vec3 m_worldUp;

        float m_fov;
        float m_aspect;
        float m_zfar;

    };
} // namespace Azure

#endif