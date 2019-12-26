#pragma once

#include <map>

#include "systems/renderer/shader.hpp"
#include "systems/renderer/shader_type.hpp"

namespace aiko
{

    class ShaderManager
    {
    public:

		ShaderManager() = default;
        ~ShaderManager() = default;

		void init();

		Shader&	getShader(ShaderType type = ShaderType::CORE);

		using ShaderMap =	std::map<ShaderType, Shader>;
		ShaderMap			m_shaders;

    };

}

