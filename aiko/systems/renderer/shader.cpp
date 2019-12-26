#include "shader.hpp"

#include <gtc/type_ptr.hpp>

#include <fstream>
#include <iostream>

namespace aiko
{

	Shader::Shader()
        : m_id(0)
    {
		
    }

	Shader::ShaderId Shader::getId()
	{
		return m_id;
	}

	void Shader::use()
	{
        // glUseProgram(m_id);
	}

	void Shader::unuse()
	{
        // glUseProgram(0);
	}

	Shader::UniformLocation Shader::getUniformLocation(char * str)
	{
        return 0;// glGetUniformLocation(m_id, str);
	}

	void Shader::setUniform1i(char * name, int n)
	{
		// (getUniformLocation(name), n);
	}

	void Shader::setUniformMatrix4fv(char * name, glm::mat4 matrix)
	{
		// glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
	}

	void Shader::setUniform3fv(char * name, glm::vec3 v)
	{
        // glUniform3fv(getUniformLocation(name), 1, glm::value_ptr(v));
	}

	bool Shader::loadShader(const ShaderType type, const std::string& vertexProgramFile, const std::string& fragmentProgramFile)
	{

		// auto loadProgram = [](std::string file, uint16_t& program, uint16_t type)
		// {
        // 
		// 	char infoLog[512];
        //     uint16_t succes;
        // 
		// 	std::string line = "";
		// 	std::string src = "";
        // 
		// 	std::ifstream in_file(file);
        // 
		// 	if (in_file.is_open())
		// 	{
		// 		while (std::getline(in_file, line))
		// 		{
		// 			src += line + "\n";
		// 		}
		// 	}
		// 	else
		// 	{
		// 		std::cout << "Error loading file " + file << std::endl;
		// 		in_file.close();
		// 		return false;
		// 	}
        // 
		// 	in_file.close();
        // 
		// 	program = glCreateShader(type);
        // 
		// 	const GLchar* vertSrc = src.c_str();
        // 
		// 	glShaderSource(program, 1, &vertSrc, NULL);
		// 	glCompileShader(program);
        // 
		// 	glGetShaderiv(program, GL_COMPILE_STATUS, &succes);
		// 	if (succes != GL_TRUE)
		// 	{
		// 		glGetShaderInfoLog(program, 512, NULL, infoLog);
		// 		std::cout << "Error compiling program" << std::endl;
		// 		std::cout << infoLog << std::endl;
		// 		return false;
		// 	}
        // 
		// 	return true;
        // 
		// };
        // 
		// uint16_t vertexShader;
        // uint16_t fragmentShader;
		// if (loadProgram(vertexProgramFile.c_str() , vertexShader, GL_VERTEX_SHADER) == false)
		// {
		// 	std::cout << "error loading " + vertexProgramFile << std::endl;
		// 	return false;
		// }
        // 
		// if (loadProgram(fragmentProgramFile.c_str(), fragmentShader, GL_FRAGMENT_SHADER) == false)
		// {
		// 	std::cout << "error loading " + fragmentProgramFile << std::endl;
		// 	return false;
		// }
        // 
		// m_id = glCreateProgram();
        // 
		// glAttachShader(m_id, vertexShader);
		// glAttachShader(m_id, fragmentShader);
        // 
		// glLinkProgram(m_id);
        // 
		// {
        // 
		// 	char infoLog[512];
        //     uint16_t succes;
        // 
		// 	glGetProgramiv(m_id, GL_LINK_STATUS, &succes);
        // 
		// 	if (succes != GL_TRUE)
		// 	{
		// 		glGetProgramInfoLog(m_id, 512, NULL, infoLog);
		// 		std::cout << "Error linking program" << std::endl;
		// 		std::cout << infoLog << std::endl;
		// 		return false;
		// 	}
        // 
		// }
        // 
		// glUseProgram(0);
		// glDeleteShader(vertexShader);
		// glDeleteShader(fragmentShader);

		return true;
	}

}

