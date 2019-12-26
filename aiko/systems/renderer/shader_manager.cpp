#include "shader_manager.hpp"

#include <iostream>

namespace aiko
{

	void ShaderManager::init()
	{
		auto core_shader = Shader();
		const auto result = core_shader.loadShader(ShaderType::CORE, "assets/vertex_core.glsl", "assets/fragment_core.glsl");

		if (result == false)
		{
			std::cout << "Error::Main.cpp::LoadShader" << std::endl;
			// TODO :: throw excetion
		}

		m_shaders.insert({ ShaderType::CORE, core_shader });

	}

	Shader & ShaderManager::getShader(ShaderType type)
	{
		auto found = m_shaders.find(type);
		if (found == m_shaders.end())
		{
			std::cout << "not found" << std::endl;
			// Thrown exception?
		}
		return found->second;
	}

}

