#pragma once

#include "config/config.hpp"
#include "modules/module.hpp"

#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <string>
#include <vector>
#include <functional>

namespace aiko
{

    class Renderer;

    class Display : public Module
    {
    public:

        Display(Engine& engine);

        void            connect(ModuleConnector& moduleConnector) override;
        virtual bool    init() override;
		virtual bool	release() override;

		glm::vec2		getFrameBufferSize();

		GLFWwindow*		getWindow() const;

        bool            isWindowOpen();

        // GLFW listeners.
        static void     windowCloseListener(GLFWwindow* win);
        static void     windowResizeListener(GLFWwindow* win, int width, int height);
        static void     keyPressListener(GLFWwindow* win, int key, int scancode, int action, int mods);
        static void     mouseMoveListener(GLFWwindow* win, double x, double y);
        static void     mouseEnterListener(GLFWwindow* win, int entered);

	private:

		GLFWwindow*		m_window;

        Renderer*       m_renderer;

    };

}

