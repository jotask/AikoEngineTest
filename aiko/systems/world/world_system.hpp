#pragma once

#include "shared/transform.hpp"
#include "systems/system.hpp"
#include "systems/entity/light.hpp"
#include "shared/types.hpp"
#include "shared/utils.hpp"

#include <glm.hpp>

#include <vector>
#include <array>

namespace aiko
{

    class AssetsSystem;

    class WorldSystem : public System
    {
    private:
        static WorldSystem * s_instance;
    public:

        WorldSystem();

        static WorldSystem* it() { return s_instance; }

        virtual ~WorldSystem() = default;

        void                init() override;
        bool                initResources() override;

        virtual void        update(const TimeStep& step) override;

    private:

    };

}

