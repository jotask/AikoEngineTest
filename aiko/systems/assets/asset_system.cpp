#include "asset_system.hpp"

#include <memory>
#include <algorithm>
#include <cassert>
#include <exception>

namespace aiko
{

    AssetsSystem * AssetsSystem::s_instance = nullptr;

    AssetsSystem::AssetsSystem()
    {
        s_instance = this;

        // FIXME
        initResources();
    }

    void AssetsSystem::connect(SystemConnector & systemConnectar, ModuleConnector & moduleConnector)
    {
    }

    void AssetsSystem::init()
    {

    }

    bool AssetsSystem::initResources()
    {
        // FIXME
        static auto initialised = false;

        if (initialised == true)
        {
            return true;
        }

        initialised = true;

        // loadResource("models/sphere/sphere.scene.xml", H3DResTypes::SceneGraph, Resources::Sphere);
        // loadResource("materials/light.material.xml", H3DResTypes::Material, Resources::LightMaterial);

        loadAll();

        return true;
    }

    void AssetsSystem::update(const TimeStep & step)
    {
    }

    Asset::AssetId AssetsSystem::getResource(const Resources resource) const
    {
        const auto foundItr = m_assets.find(resource);
        if (foundItr != m_assets.end() )
        {
            auto& asset = *foundItr;
            return asset.second->getId();
        }
        // Temporary code
        // This class needs improved, atm we are okay throwing an exception until assets handling is improved
        throw std::exception("resource not found");
    }

    Asset::AssetId AssetsSystem::loadResource(const char * path, const Asset::Types type, Resources res)
    {

        auto asset = std::make_unique<Asset>(path, type);
        asset->load();

        const auto key = asset->getId();
        m_assets.insert(std::make_pair(res, std::move(asset)));

        return key;
    }

    void AssetsSystem::loadAll()
    {
        for (auto& asset : m_assets)
        {
            asset.second->load();
        }
    }

}

