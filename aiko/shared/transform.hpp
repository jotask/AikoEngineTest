#pragma once

#include "glm.hpp"

namespace aiko
{

    class Transform
    {
    public:
        Transform();
        ~Transform() = default;

        glm::mat4 getModelMatrix();

        glm::vec3 m_position;
        glm::vec3 m_rotation;
        glm::vec3 m_scale;

    };

}
