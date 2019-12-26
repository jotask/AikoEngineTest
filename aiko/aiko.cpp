/*
 * Copyright 2011-2019 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */

#include "engine.hpp"
#include "sandbox.hpp"

int main(int argc, char **argv)
{

    aiko::Config::initGlobalConfig(argc, argv);
    sandbox::SandboxSimulation simulation;
    simulation.run();

    return EXIT_SUCCESS;
}
