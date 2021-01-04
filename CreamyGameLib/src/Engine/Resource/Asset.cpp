#include "Engine/Resource/Asset.hpp"

#include <utility>
#include <fstream>

#include "Exception/Resource/ResourceLoadFailedException.hpp"

namespace creamyLib::engine::resource
{
    Asset::Asset(const AssetConfiguration& config): config_(config) {}

    std::filesystem::path Asset::getFilePath() const
    {
        return config_.path;
    }

    bool Asset::operator==(const Asset& r) const
    {
        return config_.id == r.config_.id;
    }
}
