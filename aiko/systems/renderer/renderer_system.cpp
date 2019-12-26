#include "renderer_system.hpp"

#include "modules/module_connector.hpp"
#include "systems/system_connector.hpp"
#include "shared/utils.hpp"
#include "systems/assets/asset_system.hpp"
#include "systems/camera/camera_system.hpp"
#include "modules\display_module.hpp"

// TODO clean following includes

#include<fstream>
// #include<stb_image.h>
#include<gtc/matrix_transform.hpp>
#include<gtc/type_ptr.hpp>

namespace aiko
{

	RendererSystem * RendererSystem::s_instance = nullptr;

	RendererSystem::RendererSystem()
        :   System()
    {
		
    }

	void RendererSystem::connect(SystemConnector& systemConnectar, ModuleConnector& moduleConnector)
	{
		m_displaySystem = moduleConnector.findModule<Display>();
		m_cameraSystem = systemConnectar.findSystem<CameraSystem>();
	};

    bool RendererSystem::initResources()
    {
        return true;
    }

	void RendererSystem::preInit()
	{

		m_shaderManager.init();

		model.loadVao();

		loadTexture("assets/link.png", texture0, true);
		loadTexture("assets/brick_texture.jpg", texture1, false);

	};

	void RendererSystem::init()
	{

	};

	void RendererSystem::postInit()
	{

	};

	void RendererSystem::preUpdate(const TimeStep& step)
	{

	};

	void RendererSystem::update(const TimeStep& step)
	{

		// Update Inputs
		glfwPollEvents();
		// updateInput(window);

		// Update
		model.update(step);

	};

	void RendererSystem::postUpdate(const TimeStep& step)
	{

	};

	void RendererSystem::preRender()
	{

	};

	void RendererSystem::render()
	{
		
		// Render

		//Start render
		// glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        // 
		// auto shader = m_shaderManager.getShader();
        // 
		// shader.use();
        // 
		// // update uniforms
        // 
		// auto& currentCamera = m_cameraSystem->getCamera();
		// shader.setUniformMatrix4fv("viewMatrix", currentCamera.getViewMatrix());
		// shader.setUniformMatrix4fv("projectionMatrix", currentCamera.getProjectionMatrix());
        // 
		// shader.setUniform1i("texture0", 0);
		// shader.setUniform1i("texture1", 1);
		// shader.setUniformMatrix4fv("modelMatrix", model.getTransform().getModelMatrix());
		// shader.setUniform3fv("lightPos", light.position);
        // 
		// glActiveTexture(GL_TEXTURE0);
		// glBindTexture(GL_TEXTURE_2D, texture0);
		// glActiveTexture(GL_TEXTURE1);
		// glBindTexture(GL_TEXTURE_2D, texture1);
        // 
		// model.render(shader);
        // 
		// //End render
		// glfwSwapBuffers(m_displaySystem->getWindow());
		// glFlush();
        // 
		// glBindVertexArray(0);
		// shader.unuse();
		// glActiveTexture(0);
		// glBindTexture(GL_TEXTURE_2D, 0);
	};

	void RendererSystem::postRender()
	{ 

	};

	bool RendererSystem::loadTexture(std::string file, uint16_t & textureId, bool alpha)
	{

		// Texture
		// int image_width = 0;
		// int image_height = 0;
		// int image_chanels = 0;
		// stbi_set_flip_vertically_on_load(1);
		// stbi_uc* image;
		// if (alpha == true)
		// {
		// 	image = stbi_load(file.c_str(), &image_width, &image_height, &image_chanels, STBI_rgb_alpha);
		// }
		// else
		// {
		// 	image = stbi_load(file.c_str(), &image_width, &image_height, &image_chanels, STBI_rgb);
		// }
        // 
		// GLenum internalFormat = 0;
		// GLenum dataFormat = 0;
		// if (image_chanels == 4)
		// {
		// 	internalFormat = GL_RGBA8;
		// 	dataFormat = GL_RGBA;
		// }
		// else if (image_chanels == 3)
		// {
		// 	internalFormat = GL_RGB8;
		// 	dataFormat = GL_RGB;
		// }
        // 
		// if (image != nullptr)
		// {
        // 
		// 	glCreateTextures(GL_TEXTURE_2D, 1, &textureId);
		// 	glTextureStorage2D(textureId, 1, internalFormat, image_width, image_height);
        // 
		// 	glTextureParameteri(textureId, GL_TEXTURE_WRAP_S, GL_REPEAT);
		// 	glTextureParameteri(textureId, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// 	glTextureParameteri(textureId, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		// 	glTextureParameteri(textureId, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        // 
		// 	glTextureSubImage2D(textureId, 0, 0, 0, image_width, image_height, dataFormat, GL_UNSIGNED_BYTE, image);
        // 
		// }
		// else
		// {
		// 	std::cout << "Error::Main.cpp::LoadingTexture " << std::endl;
		// 	return false;
		// }
        // 
		// glActiveTexture(0);
		// glBindTexture(GL_TEXTURE_2D, 0);
		// stbi_image_free(image);

		return false;
	}



}

