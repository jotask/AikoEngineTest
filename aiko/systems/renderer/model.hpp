#pragma once

#include "systems/renderer/shader_type.hpp"
#include "systems/renderer/shader.hpp"
#include "shared\transform.hpp"
#include "shared\timestep.hpp"

#include <string>


namespace aiko
{

    class Model
    {

    public:

		using ModelId = uint16_t;

		Model();

        virtual ~Model() = default;

		void update(const TimeStep& step);

		ModelId getId();

		void render(Shader& shader);

		Transform& getTransform();

    private:

		friend class RendererSystem;
		
		void loadVao();

		Transform	m_transform;
		ModelId		m_vao;
		ModelId		m_vbo;
		ModelId		m_ebo;
		float angle = 0;

    };

}

