#pragma once

#include <filesystem>
#include <utility>

namespace creamyLib::engine::resource
{
    class Asset;

    struct AssetConfiguration
    {
        std::string id;
        std::filesystem::path path;

        bool operator==(const AssetConfiguration& r) const
        {
            return id == r.id && path == r.path;
        }
    };
}

namespace std
{
    template<>
    struct hash<creamyLib::engine::resource::AssetConfiguration> {
    public:
        size_t operator()(const creamyLib::engine::resource::AssetConfiguration& data) const noexcept
        {
            std::size_t v = 0;
            const std::hash<std::string> hash;
            v ^= hash(data.id);
            v ^= hash(data.path.string());

            return v;
        }
    };
}
