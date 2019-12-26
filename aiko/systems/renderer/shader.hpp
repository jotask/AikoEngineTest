#pragma once

#include "systems/renderer/shader_type.hpp"

#include <glm.hpp>

#include <string>

namespace aiko
{

    class Shader
    {

    public:

		using ShaderId = uint16_t;
		using UniformLocation = uint16_t;

		Shader();

        virtual ~Shader() = default;

		ShaderId getId();

		void use();
		void unuse();

		UniformLocation getUniformLocation(char* str);

		void setUniform1i(char* name, int n);
		void setUniformMatrix4fv(char* name, glm::mat4 matrix);
		void setUniform3fv(char* name, glm::vec3 v);

    private:

		friend class ShaderManager;

        uint16_t m_id;

		bool loadShader(const ShaderType type, const std::string& vertexProgramFile, const std::string& fragmentProgramFile);

    };

}

