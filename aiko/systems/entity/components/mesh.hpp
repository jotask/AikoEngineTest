#pragma once

#include "systems/entity/components/component.hpp"

namespace aiko
{

    class Entity;

    class Mesh : public Component
    {
    public:
        Mesh(Entity& owner);

        virtual void init() override;

    protected:

    };

}