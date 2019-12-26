#pragma once

#include "shared/types.hpp"

#include <string>

namespace aiko
{

    class Config
    {
    public:

        using GlobalConfig = aiko::AikoPtr<Config>;

        static void initGlobalConfig(int argc, char** argv);
        static GlobalConfig& it();

        Config();
        ~Config() = default;

        std::string getWindowTitle() { return "Aiko"; };

		auto getWindowWidth() { return window_width; };
		auto getWindowHeight() { return window_height; };
		auto isFullScreen() { return m_isFullscreen; };
		auto showCursorInScreen() { return m_showCursorInScreen; };
		auto shouldDrawWireframe() { return m_drawWireFrame; };
		auto getDefaultMonitor() { return m_defaultMonitor; };

    private:

        static GlobalConfig m_instance;

		const int window_width = 1024;
		const int window_height = 576;
		bool m_isFullscreen = false;
		bool m_showCursorInScreen = false;
		bool m_drawWireFrame = false;
		int m_defaultMonitor = 0;

    };

}

