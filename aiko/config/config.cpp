#include "config.hpp"

#include <cassert>
#include <iostream>

namespace aiko
{

    Config::GlobalConfig Config::m_instance = nullptr;

    void Config::initGlobalConfig(int argc, char** argv)
    {
		m_instance = std::make_shared<Config>();
    }

    Config::GlobalConfig& Config::it()
    {
        assert(m_instance != nullptr);
        return m_instance;
    }

    Config::Config()
    {

    }

}

