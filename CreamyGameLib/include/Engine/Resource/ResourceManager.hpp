#pragma once

#include <concepts>
#include <memory>
#include <unordered_map>

#include "../../InternalLib/include/ExternalLibrary.hpp"
#include "../../InternalLib/include/Resource/ResourceLoader.hpp"

#include "Resource.hpp"
#include "Asset.hpp"

namespace creamyLib::engine::resource
{
    class ResourceManager
    {
    private:
        static ResourceManager* instance_;
        static impl::LibHandlePointer libHandle_;

        ResourceManager(impl::LibHandlePointer libHandle);
        ~ResourceManager();

        static void initialize(impl::LibHandlePointer libHandle);
        static void finalize();

        std::unique_ptr<impl::resource::ResourceLoader> loader_;

        std::unordered_map<AssetConfiguration, std::weak_ptr<Resource>> resources_;

        friend class Application;

    public:
        [[nodiscard]] static ResourceManager* getInstance();

        [[nodiscard]] std::shared_ptr<Resource> getAssetResource(const Asset& asset);
    };
}
