#include "Engine/Resource/AssetManager.hpp"

#include "../../InternalLib/include/ExternalLibrary.hpp"
#include "../../InternalLib/include/Handle.hpp"

#include "Engine/Resource/Asset.hpp"
#include "Engine/Resource/AssetConfiguration.hpp"

namespace creamyLib::engine::resource
{
    AssetManager* AssetManager::instance_ = nullptr;
    impl::LibHandlePointer AssetManager::libHandle_ = nullptr;

    AssetManager::AssetManager(impl::LibHandlePointer libHandle)
    {
        AssetManager::libHandle_ = libHandle;
    } ;

    void AssetManager::initialize(impl::LibHandlePointer libHandle)
    {
        if (!instance_)
        {
            instance_ = new AssetManager(libHandle);
        }
    }

    void AssetManager::finalize()
    {
        if (!instance_) return;

        delete instance_;
    }

    AssetManager* AssetManager::getInstance()
    {
        return instance_;
    }

    std::shared_ptr<Asset> AssetManager::getAsset(const std::shared_ptr<AssetConfiguration>& config)
    {
        if(assets_.contains(config->id))
        {
            return assets_[config->id];
        }

        auto asset = std::shared_ptr<Asset>(config->createAsset());

        assets_[config->id] = asset;

        return asset;
    }
}
