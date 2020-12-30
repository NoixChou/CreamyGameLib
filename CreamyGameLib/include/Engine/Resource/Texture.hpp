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
        void disposeMemory() override;

    public:
        Texture(const impl::resource::TextureResource& texture);

        impl::resource::TextureResource getResource();
        void destroy() override;
    };
}
