#include "camera_system.hpp"

#include "systems/camera/camera.hpp"
#include "engine.hpp"
#include "modules\display_module.hpp"
#include "modules/input_module.hpp"
#include "modules/module_connector.hpp"
#include "systems/system_connector.hpp"
#include "event/engine_events.hpp"
#include "event/event_dispatcher.hpp"
#include "shared/utils.hpp"
#include "systems/entity/entity_system.hpp"

namespace aiko
{

    CameraSystem::CameraSystem()
        : System()
    {

    }

    void CameraSystem::connect(SystemConnector& systemConnectar, ModuleConnector& moduleConnector)
    {
        m_displaySystem = moduleConnector.findModule<Display>();
    }

    void CameraSystem::init()
    {

        EventSystem::it().bind<WindowResizeEvent>(this, &CameraSystem::onWindowResize);
        EventSystem::it().bind<OnMouseMoveEvent>(this, &CameraSystem::onMouseMove);

        auto* camera = EntitySystem::createEntity<Camera>(*this);
        m_cameras.push_back(camera);

    }

    void CameraSystem::update(const TimeStep & step)
    {

    }

    Camera& CameraSystem::getCamera()
    {
        assert(m_cameras.empty() == false);
        return *m_cameras.back();
    }

	Display* CameraSystem::getDisplaySystem()
	{
		return m_displaySystem;
	}

    void CameraSystem::onMouseMove(Event& event)
    {
        const auto& msg = static_cast<const OnMouseMoveEvent&>(event);
    }

    void CameraSystem::onWindowResize(Event & event)
    {
        const auto& msg = static_cast<const WindowResizeEvent&>(event);
        resizeViewport(msg.width, msg.height);
    }

    void CameraSystem::resizeViewport(const int width, const int height)
    {
        for (auto* cam : m_cameras)
        {
            cam->resizeViewport(width, height);
        }
    }

}

