#include "Engine/Resource/Texture.hpp"

#include "../../InternalLib/include/Resource/TextureResource.hpp"
#include "../../InternalLib/include/Resource/ResourceLoader.hpp"

#include "Application/Application.hpp"
#include "Engine/Resource/ResourceManager.hpp"

#include "Exception/Resource/ResourceLoadFailedException.hpp"

namespace creamyLib::engine::resource
{
    Texture::Texture(const impl::resource::TextureResource& texture): Resource(std::make_any<impl::resource::TextureResource>(texture))
    {
        
    }

    Texture::~Texture()
    {
        Texture::destroy();
    }

    impl::resource::TextureResource Texture::getResource()
    {
        return std::any_cast<impl::resource::TextureResource>(getRawResource());
    }

    void Texture::destroy()
    {
        Texture::getResource().destroy();
    }

    AssetTexture::AssetTexture(const AssetTextureConfiguration& config): Asset(config) {}

    Texture* AssetTexture::loadResource(const impl::resource::ResourceLoader* loader) const
    {
        const auto filePath = getFilePath().string();
        auto result = loader->loadTextureFromFile(filePath);
        if (!result)
        {
            throw exception::ResourceLoadFailedException(filePath, "");
        }

        return new Texture(result.value());
    }
}
