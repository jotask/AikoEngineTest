#pragma once

#include "shared/transform.hpp"

#include "glm.hpp"

namespace aiko
{

    class Light
    {
    public:

        using Color = glm::vec3;

        Light();
        virtual ~Light() = default;

        Transform&  getTranform();

        void randomise();

        Color& getColor();

        void updateLight();

    private:

        Transform   m_transform;

        float       m_radius;
        float       m_fov;
        Color       m_color;

    };

}
