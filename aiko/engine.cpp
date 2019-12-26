#include "engine.hpp"

// aiko
#include "config/config.hpp"
#include "modules/display_module.hpp"
#include "modules/renderer_module.hpp"
#include "systems/camera/camera_system.hpp"
#include "modules/log_module.hpp"
#include "modules/input_module.hpp"
#include "systems/world/world_system.hpp"
#include "modules/module_connector.hpp"
#include "systems/system_connector.hpp"
#include "event/event_dispatcher.hpp"
#include "systems/entity/entity_system.hpp"
#include "systems/assets/asset_system.hpp"
#include "systems/renderer/renderer_system.hpp"
#include "app/app.hpp"

// stl
#include <iostream>

namespace aiko
{

    Engine::Engine(Application& app, Config cfg)
        : m_app(app)
        , m_initialized(false)
        , m_running(false)
        , m_config(cfg)
        , m_display(nullptr)
        , m_renderer(nullptr)
        , m_camera(nullptr)
    {
        // Initialize GLFW
        glfwInit();
    }

    Engine::~Engine()
    {
        release();

        // Terminate GLFW
        glfwTerminate();
    }

    int Engine::run()
    {

        m_running = true;

        TimeStep timestep;

		if (m_initialized == false)
		{
			if (init() == false)
			{
				glfwTerminate();
				return -1;
			}
			m_initialized = true;
			timestep.init();
		}

        // Game loop
        while (m_display->isWindowOpen() == true)
        {

            // Calc FPS
            timestep.update();

            // Poll window events...
            glfwPollEvents();

            // update logic
            update(timestep);

            // render and finalize frame.
            render();

        }

        release();

        return 0;
    }

    void Engine::requestClosing()
    {
        m_running = false;
    }

    template <class T>
    bool Engine::initResources(T& collection)
    {
        // Add resources
        for (auto& c : collection)
        {
            // TODO error checking
            c->initResources();
        }

        return true;
    }

    void Engine::releaseResources()
    {

    }

    void Engine::update(const TimeStep& step)
    {
        for (auto& sys : m_systems)
        {
            sys->preUpdate(step);
            sys->update(step);
            sys->postUpdate(step);
        }
    }

    void Engine::render()
    {
        m_renderer->initFrame();
        for (auto& sys : m_systems)
        {
            sys->preRender();
            sys->render();
            sys->postRender();
        }
        m_renderer->endFrame();
    }

    bool Engine::initModules()
    {

        // Register modules
        m_modules.push_back(std::make_shared<Log>(*this));
        m_modules.push_back(std::make_shared<Display>(*this));
        m_modules.push_back(std::make_shared<Renderer>(*this));
        m_modules.push_back(std::make_shared<Input>(*this));

        // call all modules to connect to the other modules required
        ModuleConnector connector(m_modules);

        // connect first the engine
        this->connectModules(connector);

        for (auto& module : m_modules)
        {
            // todo error checking
            module->connect(connector);
        }

        // init all modules
        for (auto& module : m_modules)
        {
            // todo error checking
            if (module->init() == false)
            {
                return false;
            }
        }

        return true;

    }

    bool Engine::initSystems()
    {
        // Register systems
		m_systems.push_back(std::make_shared<RendererSystem>());
		m_systems.push_back(std::make_shared<EntitySystem>());
        m_systems.push_back(std::make_shared<CameraSystem>());
        m_systems.push_back(std::make_shared<WorldSystem>());
        m_systems.push_back(std::make_shared<AssetsSystem>());

        // call all modules to systems to the other stystems required
        ModuleConnector moduleConnector(m_modules);
        SystemConnector systemConnector(m_systems);

        // connect first the engine
        this->connectSystems(systemConnector);

        for (auto& system : m_systems)
        {
            // todo error checking
            system->connect(systemConnector, moduleConnector);
        }

        // Init systems resources
        if (initResources<Systems>(m_systems) == false)
        {
            std::cout << "Unable to initialize system resources" << std::endl;
            return false;
        }

        // init all systems
        for (auto& system : m_systems)
        {
            system->preInit();
            system->init();
            system->postInit();
        }


        return true;

    }

    bool Engine::init()
    {

        // bind to events
        {
            EventSystem::it().bind<WindowCloseEvent>(this, &Engine::onWindowClose);
        }

        initModules();

        initSystems();

        m_app.init();

        return true;
    }

    void Engine::release()
    {
		for (auto& sys : m_systems)
		{
			sys->release();
		}
		for (auto& mds : m_modules)
		{
			mds->release();
		}
    }

    void Engine::onWindowClose(Event & ent)
    {
		requestClosing();
    }

    Config& Engine::getConfig()
    {
		return m_config;
    }

    void Engine::connectModules(ModuleConnector& moduleConnector)
    {
        m_display = moduleConnector.findModule<Display>();
        m_renderer = moduleConnector.findModule<Renderer>();
        m_input = moduleConnector.findModule<Input>();
    }

    void Engine::connectSystems(SystemConnector& systemConnector)
    {
        m_camera = systemConnector.findSystem<CameraSystem>();
    }

}

