#include "camera.hpp"

#include "systems/entity/components/mesh.hpp"
#include "shared/utils.hpp"
#include "engine.hpp"
#include "modules/renderer_module.hpp"
#include "modules/input_module.hpp"
#include "modules/module_connector.hpp"
#include "systems/system_connector.hpp"
#include "event/engine_events.hpp"
#include "event/event_dispatcher.hpp"
#include "shared/utils.hpp"
#include "systems\camera\camera_system.hpp"
#include "modules\display_module.hpp"

// behaviour
#include "systems/camera/behaviour/fps_behaviour.hpp"
#include "systems/camera/behaviour/orbital_behaviour.hpp"
#include "systems/camera/behaviour/dev_behaviour.hpp"

#include "GLFW/glfw3.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include <memory>

namespace aiko
{

    Camera::Camera(CameraSystem& cameraSystem)
        : m_cameraSystem(cameraSystem)
        , m_fov(45.0f)
        , m_nearPlane(0.1f)
        , m_farPlane(1000.0f)
        , m_type(BehaviourType::DEV)
        , m_behaviour(nullptr)
		, m_position(0.0f, 0.0f, 3.0f)
		, m_front(0.0f, 0.0f, -1.0f)
		, m_up(0.0f, 1.0f, 0.0f)
    {

        // switch (m_type)
        // {
        // case BehaviourType::DEV:
        //     createCameraBehaviour<DevBehaviour>();
        //     break;
        // case BehaviourType::FPS:
        //     createCameraBehaviour<FpsBehaviour>();
        //     break;
        // case BehaviourType::ORBITAL:
        //     createCameraBehaviour<OrbitalBehaviour>();
        //     break;
        // case BehaviourType::NONE:
        //     assert(false);
        //     break;
        // }

    }

    template<class T>
    void Camera::createCameraBehaviour()
    {
        assert(m_behaviour == nullptr);
        auto& ptr = std::make_unique<T>(*this);
        m_behaviour = std::move(ptr);
    }

    void Camera::resizeViewport(const int width, const int height)
    {

    }

    void Camera::init()
    {
    }

    void Camera::update(const TimeStep & step)
    {
        if (m_behaviour != nullptr)
        {
			m_behaviour->update(step);
        }
    }

    float Camera::getFOV() const
    {
        return m_fov;
    }

    float Camera::getNearPlane() const
    {
        return m_nearPlane;
    }

    float Camera::getFarPlane() const
    {
        return m_farPlane;
    }

    void Camera::lookAt(const glm::vec3 target)
    {

    }

    void Camera::updateTransform()
    {

    }

	glm::mat4 Camera::getViewMatrix()
	{
		return glm::lookAt(m_position, m_position + m_front, m_up);
	}

	glm::mat4 Camera::getProjectionMatrix()
	{
		const auto framBufferSize = m_cameraSystem.getDisplaySystem()->getFrameBufferSize();
		return glm::perspective(glm::radians(m_fov), static_cast<float>(framBufferSize.x / framBufferSize.y), m_nearPlane, m_farPlane);
	}

}

