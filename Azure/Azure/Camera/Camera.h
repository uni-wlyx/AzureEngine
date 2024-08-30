#ifndef CAMERA_H
#define CAMERA_H

#pragma once

#include <glm/glm.hpp>

namespace Azure
{
    class Camera 
    {
    public:
        Camera() = default;
        virtual ~Camera() = default;

	    const glm::vec3& GetPosition() const { return m_position; }
		void SetPosition(const glm::vec3& position) { m_position = position; UpDateViewMatrix(); }

        const glm::vec3& GetRotation() const { return {m_pitch, m_yaw, m_roll}; }
        void SetRotation(const glm::vec3& rotation) { m_pitch = rotation.x; m_yaw = rotation.y;m_roll = rotation.z; UpDateViewMatrix(); }

		const glm::mat4& GetProjectionMatrix() const { return m_projectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_viewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const { return m_viewProjectionMatrix; }

    protected:
        void UpDateViewMatrix();
        virtual void UpDateProjectionMatrix() {};
    protected:
        glm::mat4 m_projectionMatrix;
        glm::mat4 m_viewMatrix;
        glm::mat4 m_viewProjectionMatrix;

        glm::vec3 m_position = {0.0f, 0.0f, 0.0f};

        float m_pitch = 0.0f;
        float m_roll  = 0.0f;
        float m_yaw   = 0.0f;
        // glm::vec3 m_scale; // 大小应该没有

        glm::vec3 m_front;
        glm::vec3 m_up;
        glm::vec3 m_right;
        glm::vec3 m_worldUp;

    };
} // namespace Azure

#endif