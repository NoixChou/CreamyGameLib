#pragma once

#include <memory>

#include "ResourceManager.hpp"

namespace creamyLib::engine::resource
{
    template<class T>
    class ResourcePrefab
    {
    private:
        std::shared_ptr<T> resource_;

    public:
        ResourcePrefab(const std::shared_ptr<Resource>& resource): resource_(std::dynamic_pointer_cast<T>(resource)) {}
        ResourcePrefab(const Asset& asset): ResourcePrefab(ResourceManager::getInstance()->getAssetResource(asset)) {}

        const std::shared_ptr<T>& operator->() const
        {
            return resource_;
        }

        operator bool() const
        {
            return static_cast<bool>(resource_);
        }
    };
}
