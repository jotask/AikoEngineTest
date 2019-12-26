#pragma once

#include "shared/transform.hpp"
#include "systems/system.hpp"
#include "systems/camera/camera.hpp"

#include <vector>

namespace aiko
{

    class Display;
    class Event;

    class CameraSystem : public System
    {
    public:

        CameraSystem();

        virtual ~CameraSystem() = default;

        void                connect(SystemConnector& systemConnectar, ModuleConnector& moduleConnector) override;
        void                init() override;

        virtual void        update(const TimeStep& step) override;

        Camera&				getCamera();

		Display*			getDisplaySystem();

    private:

        void                onMouseMove(Event&);
        void                onWindowResize(Event&);
        void                resizeViewport(const int width, const int height);

        // Systems
        Display*           m_displaySystem;

        using Cameras       = std::vector<Camera*>;
        Cameras             m_cameras;

    };

}

