#include "log_module.hpp"

#include "modules/module_connector.hpp"

namespace aiko
{

    Log::Log(Engine& engine)
        : Module(engine)
    {

    }


    void Log::connect(ModuleConnector& moduleConnector)
    {

    }

    bool Log::init()
    {
        return true;
    }

}

