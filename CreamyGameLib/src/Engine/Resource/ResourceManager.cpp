#include "Engine/Resource/ResourceManager.hpp"

#include <iostream>

#include "../../InternalLib/include/Resource/ResourceLoader.hpp"

#include "Exception/Resource/ResourceLoadFailedException.hpp"

namespace creamyLib::engine::resource
{
    ResourceManager* ResourceManager::instance_ = nullptr;
    impl::LibHandlePointer ResourceManager::libHandle_ = nullptr;

    ResourceManager::ResourceManager(impl::LibHandlePointer libHandle)
    {
        ResourceManager::libHandle_ = libHandle;

        loader_ = std::make_unique<impl::resource::ResourceLoader>(ResourceManager::libHandle_);
    }

    ResourceManager::~ResourceManager()
    {
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

    std::shared_ptr<Resource> ResourceManager::getAssetResource(const Asset& asset)
    {
        if(const auto iterator = resources_.find(asset.config_); iterator != resources_.end())
        {
            auto resource = iterator->second.lock();
            if (resource)
            {
                return resource;
            }

            resources_.erase(iterator);
        }

        std::shared_ptr<Resource> resource;

        try
        {
            resource.reset(asset.loadResource(loader_.get()));
        }catch ([[maybe_unused]] exception::ResourceLoadFailedException& e)
        {
            throw;
        }

        resources_[asset.config_] = resource;

        return resource;
    }
}
