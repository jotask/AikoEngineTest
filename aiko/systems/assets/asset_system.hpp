#pragma once

#include "systems/system.hpp"
#include "shared/types.hpp"
#include "systems/assets/asset.hpp"

#include <map>

namespace aiko
{

    class AssetsSystem : public System
    {
    private:

        static AssetsSystem * s_instance;

    public:

        // Temporary enum to indentify resources
        // This will come ideally from a file maybe?

        enum class Resources
        {
            LightMaterial,
            Sphere
        };

        static AssetsSystem* it() { return s_instance; }

        AssetsSystem();

        virtual ~AssetsSystem() = default;

        void            connect(SystemConnector& systemConnectar, ModuleConnector& moduleConnector) override;
        void            init() override;
        bool            initResources() override;

        void            update(const TimeStep& step) override;

        Asset::AssetId  getResource(const Resources resource) const;

    private:

        Asset::AssetId  loadResource(const char* path, const Asset::Types type, Resources resource);
        void            loadAll();

        // using Assets    = std::map<Asset::AssetId, AikoUPtr<Asset>>;
        using Assets    = std::map<Resources, AikoUPtr<Asset>>;

        Assets          m_assets;

    };

}

