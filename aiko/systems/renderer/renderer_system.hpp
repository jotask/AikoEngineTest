#pragma once

#include "shared/transform.hpp"
#include "systems/system.hpp"
#include "systems/entity/light.hpp"
#include "shared/types.hpp"
#include "shared/utils.hpp"

#include <glm.hpp>

#include <vector>
#include <array>

#include "shader_manager.hpp"
#include "model.hpp"

namespace aiko
{

	class Display;
	class AssetsSystem;
	class CameraSystem;

    class RendererSystem : public System
    {
    private:
        static RendererSystem * s_instance;
    public:

		RendererSystem();

        static RendererSystem* it() { return s_instance; }

        virtual ~RendererSystem() = default;

		virtual void        connect(SystemConnector& systemConnectar, ModuleConnector& moduleConnector) override;

		virtual bool        initResources() override;

		virtual void        preInit() override;
		virtual void        init() override;
		virtual void        postInit() override;

		virtual void        preUpdate(const TimeStep& step) override;
		virtual void        update(const TimeStep& step)override;
		virtual void        postUpdate(const TimeStep& step) override;

		virtual void        preRender() override;
		virtual void        render() override;
		virtual void        postRender() override;

    private:

		bool				loadTexture(std::string file, uint16_t& textureId, bool alpha = true);

		Display*			m_displaySystem;
		CameraSystem*		m_cameraSystem;
		ShaderManager		m_shaderManager;

		Model				model;

        uint16_t vao;
        uint16_t texture0;
        uint16_t texture1;

		struct Light
		{
			glm::vec3 position = glm::vec3(0.0f, 0.0f, 1.0f);
		};
		Light light;


    };

}

