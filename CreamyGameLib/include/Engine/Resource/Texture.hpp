#pragma once

#include "Resource.hpp"

namespace creamyLib::impl::resource
{
    struct TextureResource;
}

namespace creamyLib::engine::resource
{
    class Texture : public Resource
    {
    private:
        void DisposeMemory() override;

    public:
        Texture(const impl::resource::TextureResource& texture);

        impl::resource::TextureResource GetResource();
        void Destroy() override;
    };
}
