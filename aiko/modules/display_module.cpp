#include "modules/display_module.hpp"

#include "engine.hpp"
#include "config/config.hpp"
#include "modules/renderer_module.hpp"
#include "modules/input_module.hpp"
#include "modules/module_connector.hpp"
#include "event/engine_events.hpp"
#include "event/event_dispatcher.hpp"
#include "config/config.hpp"

#include <glm.hpp>

#include <string>
#include <iostream>

namespace aiko
{

    Display::Display(Engine& eng)
        : Module(eng)
		, m_window(nullptr)
    {

    }

    void Display::connect(ModuleConnector& moduleConnector)
    {
        m_renderer = moduleConnector.findModule<Renderer>();
    }

    bool Display::init()
    {

        auto glfw_errorCallback = [](int error, const char *description)
        {
            fprintf(stderr, "GLFW error %d: %s\n", error, description);
        };

        auto glfw_keyCallback = [](GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            if (key == GLFW_KEY_F1 && action == GLFW_RELEASE)
            {
                Renderer::s_showStats = !Renderer::s_showStats;
            }
        };

        // Create a GLFW window without an OpenGL context.
        glfwSetErrorCallback(glfw_errorCallback);
        if (!glfwInit())
            return 1;
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        m_window = glfwCreateWindow(1024, 768, "helloworld", nullptr, nullptr);
        if (m_window == nullptr)
        {
            return false;
        }

        glfwSetKeyCallback(m_window, glfw_keyCallback);

		// Init GLFW
		// glfwInit();
        // 
		// const auto cfg = aiko::Config::it();
        // 
		// // Create Window
		// const auto WINDOW_WIDTH = cfg->getWindowWidth();
		// const auto WINDOW_HEIGHT = cfg->getWindowHeight();
        // 
		// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		// glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
        // 
		// // MAC OS
		// //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        // 
		// if (cfg->isFullScreen() == true)
		// {
		//     const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		// 	
		// 	m_window = glfwCreateWindow(mode->width, mode->height, cfg->getWindowTitle().c_str(), glfwGetPrimaryMonitor(), NULL);
		// }
		// else
		// {
		// 	m_window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, cfg->getWindowTitle().c_str(), NULL, NULL);
		// }
        // 
		// // Disable vertical synchronization
		// glfwSwapInterval(0);
        // 
		// // // Set listeners
		// glfwSetWindowCloseCallback(m_window, windowCloseListener);
		// glfwSetWindowSizeCallback(m_window, windowResizeListener);
		// glfwSetKeyCallback(m_window, keyPressListener);
		// glfwSetCursorPosCallback(m_window, mouseMoveListener);
		// glfwSetCursorEnterCallback(m_window, mouseEnterListener);
        // 
		// glfwSetWindowUserPointer(m_window, &m_engine);
		// glfwMakeContextCurrent(m_window);
        // 
		// // Init Glew (Needs opengl context)
		// glewExperimental = GL_TRUE;
		// if (glewInit() != GLEW_OK)
		// {
		// 	std::cout << "Error::Main.cpp::GLEW_INIT_FAIL" << std::endl;
		// 	glfwTerminate();
		// 	// TODO :: throw excetion
		// 	return false;
		// }
        // 
		// // OpenGL options
		// glEnable(GL_DEPTH_TEST);
		// // glEnable(GL_CULL_FACE);
		// // glCullFace(GL_BACK);
		// // glFrontFace(GL_CCW);
        // 
		// glEnable(GL_BLEND);
		// glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        // 
		// if (cfg->shouldDrawWireframe() == true)
		// {
		// 	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		// }
		// else
		// {
		// 	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		// }


        return m_window != nullptr;
    }


	bool Display::release()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return true;
	}

	glm::vec2 Display::getFrameBufferSize()
	{
		int frameBufferWidth = 0;
		int frameBufferHeight = 0;
		glfwGetFramebufferSize(m_window, &frameBufferWidth, &frameBufferHeight);
		auto frameBufferSize = glm::vec2(frameBufferWidth, frameBufferHeight);
		return frameBufferSize;
	}

    GLFWwindow* Display::getWindow() const
    {
        return m_window;
    }

    bool Display::isWindowOpen()
    {
        return glfwWindowShouldClose(m_window) == false;
    }

    void Display::windowCloseListener(GLFWwindow* win)
    {
        WindowCloseEvent even;
        aiko::EventSystem::it().sendEvent(even);
    }

    void Display::windowResizeListener(GLFWwindow* win, int width, int height)
    {
        WindowResizeEvent even(width, height);
        aiko::EventSystem::it().sendEvent(even);
    }

    void Display::keyPressListener(GLFWwindow* win, int key, int scancode, int action, int mods)
    {
        OnKeyPressedEvent evnt(key, scancode, action, mods);
        EventSystem::it().sendEvent(evnt);
    }

    void Display::mouseMoveListener(GLFWwindow* win, double x, double y)
    {
        static auto prev = glm::vec2(x, y);
        OnMouseMoveEvent evnt(static_cast<float>(x), static_cast<float>(y), prev.x, prev.y);
        EventSystem::it().sendEvent(evnt);
        prev = { x, y };
    }

    void Display::mouseEnterListener(GLFWwindow* win, int entered)
    {
        OnMouseEnterEvent evnt(entered != 0);
        EventSystem::it().sendEvent(evnt);
    }

}

