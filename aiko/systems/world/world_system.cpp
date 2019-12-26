#include "world_system.hpp"

#include "modules/module_connector.hpp"
#include "systems/system_connector.hpp"
#include "shared/utils.hpp"
#include "systems/entity/entity_system.hpp"
#include "systems/assets/asset_system.hpp"


namespace aiko
{

    WorldSystem * WorldSystem::s_instance = nullptr;

    WorldSystem::WorldSystem()
        :   System()
    {

    }


    void WorldSystem::init()
    {

    }

    bool WorldSystem::initResources()
    {
        return true;
    }

    void WorldSystem::update(const TimeStep & step)
    {

    }

}

