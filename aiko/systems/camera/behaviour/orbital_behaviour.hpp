#pragma once

#include "systems/camera/behaviour/behaviour.hpp"

#include <glm.hpp>

namespace aiko
{

    class OrbitalBehaviour : public Behaviour
    {
    public:

        OrbitalBehaviour(Camera& camera);
        virtual ~OrbitalBehaviour();

        virtual void createCamera(int& camNode);
        virtual void update(const TimeStep & step);

    private:

		int             m_anchor;

        glm::vec3           m_center;

    };

}
