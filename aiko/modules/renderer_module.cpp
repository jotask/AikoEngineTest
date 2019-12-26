#include "renderer_module.hpp"

#include "modules/display_module.hpp"
#include "modules/module_connector.hpp"
#include "event/engine_events.hpp"
#include "event/event_dispatcher.hpp"

#include <stdio.h>
#include <bx/bx.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <GLFW/glfw3.h>
#if BX_PLATFORM_LINUX
#define GLFW_EXPOSE_NATIVE_X11
#elif BX_PLATFORM_WINDOWS
#define GLFW_EXPOSE_NATIVE_WIN32
#endif
#include <GLFW/glfw3native.h>

namespace aiko
{


    bool Renderer::Renderer::s_showStats = false;

    Renderer::Renderer(Engine& engine)
        : Module(engine)
    {

    }


    void Renderer::resizeViewport(const int width, const int height)
    {
        // glViewport(0, 0, width, height);
    }

    void Renderer::connect(ModuleConnector& moduleConnector)
    {
        m_display = moduleConnector.findModule<Display>();
    }

    void Renderer::initFrame()
    {
        glfwPollEvents();
    }

    void Renderer::endFrame()
    {

        auto window = m_display->getWindow();
        const bgfx::ViewId kClearView = 0;

        int width, height;
        glfwGetWindowSize(window, &width, &height);

        // Handle window resize.
        int oldWidth = width, oldHeight = height;
        glfwGetWindowSize(window, &width, &height);
        if (width != oldWidth || height != oldHeight) {
            bgfx::reset((uint32_t)width, (uint32_t)height, BGFX_RESET_VSYNC);
            bgfx::setViewRect(kClearView, 0, 0, bgfx::BackbufferRatio::Equal);
        }
        // This dummy draw call is here to make sure that view 0 is cleared if no other draw calls are submitted to view 0.
        bgfx::touch(kClearView);
        // Use debug font to print information about this example.
        bgfx::dbgTextClear();
        bgfx::dbgTextPrintf(0, 0, 0x0f, "Press F1 to toggle stats.");
        const bgfx::Stats* stats = bgfx::getStats();
        bgfx::dbgTextPrintf(0, 1, 0x0f, "Backbuffer %dW x %dH in pixels, debug text %dW x %dH in characters.", stats->width, stats->height, stats->textWidth, stats->textHeight);
        // Enable stats or debug text.
        bgfx::setDebug(s_showStats ? BGFX_DEBUG_STATS : BGFX_DEBUG_TEXT);

        // Advance to next frame. Process submitted rendering primitives.
        bgfx::frame();
    }

    void Renderer::onWindowResize(Event & event)
    {
        const auto& msg = static_cast<const WindowResizeEvent&>(event);
        resizeViewport(msg.width, msg.height);
    }

    bool Renderer::init()
    {

        auto* window = m_display->getWindow();

        // Call bgfx::renderFrame before bgfx::init to signal to bgfx not to create a render thread.
        // Most graphics APIs must be used on the same thread that created the window.
        bgfx::renderFrame();

        // Initialize bgfx using the native window handle and window resolution.
        bgfx::Init init;
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
        init.platformData.ndt = glfwGetX11Display();
        init.platformData.nwh = (void*)(uintptr_t)glfwGetX11Window(window);
#elif BX_PLATFORM_OSX
        init.platformData.nwh = glfwGetCocoaWindow(window);
#elif BX_PLATFORM_WINDOWS
        init.platformData.nwh = glfwGetWin32Window(window);
#endif
        int width, height;
        glfwGetWindowSize(window, &width, &height);
        init.resolution.width = (uint32_t)width;
        init.resolution.height = (uint32_t)height;
        init.resolution.reset = BGFX_RESET_VSYNC;
        if (!bgfx::init(init))
            return 1;
        // Set view 0 to the same dimensions as the window and to clear the color buffer.
        const bgfx::ViewId kClearView = 0;
        bgfx::setViewClear(kClearView, BGFX_CLEAR_COLOR);
        bgfx::setViewRect(kClearView, 0, 0, bgfx::BackbufferRatio::Equal);

        EventSystem::it().bind<WindowResizeEvent>(this, &Renderer::onWindowResize);
        return true;
    }

    bool Renderer::release()
    {
        // bgfx::shutdown();
        glfwTerminate();
        return true;
    }

    bool Renderer::initResources()
    {
        return true;
    }

}

