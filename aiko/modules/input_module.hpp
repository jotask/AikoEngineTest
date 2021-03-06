#pragma once

#include "modules/module.hpp"

namespace aiko
{

    // Forward declaration
    class Display;

    class Event;

    class Input : public Module
    {
    public:

        Input           (Engine& engine);
        virtual         ~Input() = default;

        void            connect(ModuleConnector& moduleConnector) override;
        bool            init();

        bool            isKeyDown(int key) const;

    private:

        void            onKeyEventHandler(Event&);
        void            onMouseMoveHandler(Event&);

        Display*        m_display;

    };

}

