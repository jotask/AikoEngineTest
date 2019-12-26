#include "orbital_behaviour.hpp"

#include "modules/renderer_module.hpp"
#include "systems/camera/camera.hpp"

#include "systems/world/world_system.hpp"

namespace aiko
{

    OrbitalBehaviour::OrbitalBehaviour(Camera& cam)
        : Behaviour(cam, BehaviourType::ORBITAL)
        , m_anchor(0)
        , m_center()
    {
        auto& transform = m_camera.getTransform();
        transform.m_position.x = 5;
        transform.m_position.y = 3;
        transform.m_position.z = 19;
    }

    OrbitalBehaviour::~OrbitalBehaviour()
    {
    }

    void OrbitalBehaviour::createCamera(int & camNode)
    {

    }

    void OrbitalBehaviour::update(const TimeStep & step)
    {

        static auto dt = 0.0f;
        dt += step.getDelta() * 0.5f;

        auto& p = m_camera.getTransform().m_position;

		float radius = 1.0f;

        p.x = radius * cos(dt);
        p.z = radius * sin(dt);

        m_camera.lookAt();

    }

}
