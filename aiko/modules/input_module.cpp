#include "input_module.hpp"

#include "modules/display_module.hpp"
#include "modules/module_connector.hpp"
#include "event/engine_events.hpp"
#include "event/event_dispatcher.hpp"
#include "modules/renderer_module.hpp"

namespace aiko
{

    Input::Input(Engine& engine)
        : Module(engine)
        , m_display(nullptr)
    {

    }

    void Input::connect(ModuleConnector & moduleConnector)
    {
        m_display = moduleConnector.findModule<Display>();
    }

    bool Input::init()
    {
        EventSystem::it().bind<OnKeyPressedEvent>(this, &Input::onKeyEventHandler);
        EventSystem::it().bind<OnMouseMoveEvent>(this, &Input::onMouseMoveHandler);

        auto glfw_keyCallback = [](GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            if (key == GLFW_KEY_F1 && action == GLFW_RELEASE)
            {
                Renderer::s_showStats = !Renderer::s_showStats;
            }
        };

        auto* window = m_display->getWindow();
        glfwSetKeyCallback(window, glfw_keyCallback);

        return true;
    }

    bool Input::isKeyDown(int key) const
    {
		return false; // glfwGetKey(m_display->getWindowHandle(), key) == GLFW_PRESS;
    }

    void Input::onKeyEventHandler(Event& event)
    {
        const auto& msg = static_cast<const OnKeyPressedEvent&>(event);

        if (msg.action != GLFW_PRESS)
            return;

        switch (msg.key)
        {
        case GLFW_KEY_ESCAPE:
        {
            WindowCloseEvent event;
            EventSystem::it().sendEvent(event);
        }
        break;
        
        }
    }

    void Input::onMouseMoveHandler(Event& event)
    {
        const auto& msg = static_cast<const OnMouseMoveEvent&>(event);
        const auto dx = msg.x - msg.prevX;
        const auto dy = msg.prevY - msg.y;
    }

}

