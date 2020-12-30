#include "Engine/Resource/ResourceManager.hpp"

#include <iostream>

#include "Exception/Resource/ResourceLoadFailedException.hpp"
#include "Resource/ResourceLoader.hpp"

namespace creamyLib::engine::resource
{
    ResourceManager* ResourceManager::instance_ = nullptr;
    impl::LibHandlePointer ResourceManager::libHandle_ = nullptr;

    ResourceManager::ResourceManager(impl::LibHandlePointer libHandle)
    {
        ResourceManager::libHandle_ = libHandle;
    }

    ResourceManager::~ResourceManager()
    {
        for(auto* resource : resources_)
        {
            resource->destroy();
            delete resource;
        }

        resources_.clear();
    }

    void ResourceManager::initialize(impl::LibHandlePointer libHandle)
    {
        if(!instance_)
        {
            instance_ = new ResourceManager(libHandle);
        }
    }

    void ResourceManager::finalize()
    {
        if (!instance_) return;

        delete instance_;
    }

    ResourceManager* ResourceManager::getInstance()
    {
        return instance_;
    }

    void ResourceManager::removeResource(Resource* resource)
    {
        if (!resource) return;

        const auto iterator = std::find(resources_.begin(), resources_.end(), resource);

        if (iterator != resources_.end())
        {
            resource->disposeMemory();
            resources_.erase(iterator);
        }
    }

    Texture* ResourceManager::getResourceTextureFromFile(const std::string& fileName)
    {
        auto result = impl::resource::LoadTextureFromFile(ResourceManager::libHandle_, fileName);
        if(!result)
        {
            throw exception::ResourceLoadFailedException(fileName, "");
        }

        auto* texture = new Texture(result.value());

        resources_.emplace_back(texture);

        return texture;
    }
}
