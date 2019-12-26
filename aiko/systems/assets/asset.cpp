#include "asset.hpp"

namespace aiko
{

    Asset::Asset(const char* path, const Types type)
        : m_path(path)
        , m_type(type)
        , m_resource(-1)
    {
        
    }

    void Asset::load()
    {
        // m_resource = h3dAddResource(m_type, m_path.c_str(), 0);
    }

    const Asset::AssetId Asset::getId() const
    {
        return m_resource;
    }

    const Asset::Types Asset::getType() const
    {
        return m_type;
    }

}
