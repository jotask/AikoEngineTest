#pragma once

#include "shared/timestep.hpp"
#include "systems/camera/behaviour/behaviour_types.hpp"

namespace aiko
{
    class Camera;
    class Behaviour
    {
    public:
        Behaviour(Camera&, BehaviourType);
        virtual ~Behaviour() = default;

        virtual void createCamera(int& camNode) = 0;
        virtual void update(const TimeStep & step) = 0;

        const BehaviourType getType() const;

    protected:

        const BehaviourType m_type;

        Camera & m_camera;

    };

}
