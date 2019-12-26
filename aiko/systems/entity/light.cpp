#include "light.hpp"

#include "shared/utils.hpp"

#include <string>

namespace aiko
{

    Light::Light()
        : m_transform()
        , m_radius(50)
        , m_fov(90)
        , m_color({ 1.0f, 0.8f, 0.7f })
    {

    }

    Transform & Light::getTranform()
    {
        return m_transform;
    }

    void Light::randomise()
    {

    }

    Light::Color& Light::getColor()
    {
        return m_color;
    }

    void Light::updateLight()
    {

    }

}
