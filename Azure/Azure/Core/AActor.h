#ifndef AACTOR_H
#define AACTOR_H

#pragma once

#include <glm/glm.hpp>

namespace Azure
{
    struct Transform
    {
        glm::vec3 location;
        glm::vec3 rotation;
        glm::vec3 scale;
    };

    class AActor
    {
    public:

        const Transform &getTransform() const {return {m_position, m_rotation,m_scale};};
        void setTransform(const Transform transform) {m_position = transform.location; m_rotation = transform.rotation; m_scale = transform.scale;};

        const glm::vec3 &getLocation() const {return m_position;};
        void setLocation(const glm::vec3 &location) {m_position = location;};

        const glm::vec3 &getRotation() const {return m_rotation;};
        void setRotation(const glm::vec3 &rotation) {m_rotation = rotation;};

        const glm::vec3 &getScale() const {return m_scale;};
        void setScale(const glm::vec3 &scale) {m_scale = scale;};

    protected:
        glm::vec3 m_position;
        glm::vec3 m_rotation;
        glm::vec3 m_scale;

    };

} // namespace Azure

#endif