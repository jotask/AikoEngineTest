#pragma once

#include <engine.hpp>

#include <config/config.hpp>
#include <app/app.hpp>

namespace sandbox
{

    class SandboxSimulation : public aiko::Application
    {
    public:
		SandboxSimulation( aiko::Config& cfg = *aiko::Config::it());

        virtual void        init();

    private:

    };

}
