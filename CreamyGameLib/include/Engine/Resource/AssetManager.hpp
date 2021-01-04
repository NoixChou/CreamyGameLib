#pragma once

#include <memory>
#include <unordered_map>

namespace creamyLib::impl
{
    struct LibHandle;
    using LibHandlePointer = LibHandle*;
}

namespace creamyLib::engine::resource
{
    struct AssetConfiguration;
    class Asset;

    class AssetManager
    {
    private:
        static AssetManager* instance_;
        static impl::LibHandlePointer libHandle_;

        [[deprecated]]
        AssetManager(impl::LibHandlePointer libHandle);
        ~AssetManager() = default;

        [[deprecated]]
        static void initialize(impl::LibHandlePointer libHandle);
        static void finalize();

        std::unordered_map<std::string, std::shared_ptr<Asset>> assets_;

        friend class Application;

    public:
        [[deprecated]]
        [[nodiscard]] static AssetManager* getInstance();

        [[deprecated]]
        [[nodiscard]] std::shared_ptr<Asset> getAsset(const std::shared_ptr<AssetConfiguration>& config);
    };
}
