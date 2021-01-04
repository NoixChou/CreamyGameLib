#pragma once

#include <filesystem>

#include "AssetConfiguration.hpp"
#include "Resource.hpp"

namespace creamyLib {
    namespace impl {
        namespace resource {
            class ResourceLoader;
        }
    }
}

namespace creamyLib::engine::resource
{
    class Asset
    {
    private:
        AssetConfiguration config_;

        friend class ResourceManager;

    public:
        Asset(const AssetConfiguration& config);

        [[nodiscard]] std::filesystem::path getFilePath() const;

        [[nodiscard]] virtual Resource* loadResource(const impl::resource::ResourceLoader* loader) const = 0;

        bool operator==(const Asset& r) const;
    };
}
