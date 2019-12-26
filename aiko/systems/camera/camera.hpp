#pragma once

#include "shared/types.hpp"
#include "systems/entity/entity.hpp"
#include "systems/camera/behaviour/behaviour.hpp"

#include "glm.hpp"

#include <vector>
#include <memory>

namespace aiko
{

    class CameraSystem;

    class Camera : public Entity
    {
    public:
        Camera(CameraSystem& cameraSystem);
        virtual ~Camera() = default;

        virtual void        init();
        virtual void        update(const TimeStep & step);
        virtual void        render() {};

        float               getFOV() const;
        float               getNearPlane() const;
        float               getFarPlane() const;

        void                resizeViewport(const int width, const int height);

        void                lookAt(const glm::vec3 target = glm::vec3());

        virtual void        updateTransform();

		glm::mat4			getViewMatrix();
		glm::mat4			getProjectionMatrix();

    private:

		glm::vec3			m_position;
		glm::vec3			m_front;
		glm::vec3			m_up;

        CameraSystem&		m_cameraSystem;

        float               m_fov;
        float               m_nearPlane;
        float               m_farPlane;

        BehaviourType       m_type;

        using CameraBehaviour = AikoUPtr<Behaviour>;
        CameraBehaviour      m_behaviour;

        template<class T>
        void createCameraBehaviour();

    };

}
