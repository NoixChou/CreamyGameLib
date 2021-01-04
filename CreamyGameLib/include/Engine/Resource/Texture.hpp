#pragma once

#include "Asset.hpp"
#include "Resource.hpp"

namespace creamyLib::impl::resource
{
    struct TextureResource;
}

namespace creamyLib::engine::resource
{
    struct AssetTextureConfiguration;

    class Texture : public Resource
    {
    public:
        Texture(const impl::resource::TextureResource& texture);
        ~Texture() override;

        [[nodiscard]] impl::resource::TextureResource getResource();
        void destroy() override;
    };

    class AssetTexture : public Asset
    {
    public:
        AssetTexture(const AssetTextureConfiguration& config);
        [[nodiscard]] Texture* loadResource(const impl::resource::ResourceLoader* loader) const override;
    };

    struct AssetTextureConfiguration : public AssetConfiguration
    {};
}
