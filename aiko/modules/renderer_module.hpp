#pragma once

#include "modules/module.hpp"

#include <vector>

namespace aiko
{

    class Event;
    class Display;

    class Renderer : public Module
    {
    public:

        Renderer(Engine& engine);
        virtual ~Renderer() = default;

        static bool  s_showStats;

        virtual bool init();
        virtual bool release() override;
		virtual bool initResources() final override;

        virtual void connect(ModuleConnector& moduleConnector) override;

        void initFrame();
        void endFrame();

    private:
        void			resizeViewport(const int width, const int height);

        void            onWindowResize(Event& );

        Display*        m_display;

    };

}

