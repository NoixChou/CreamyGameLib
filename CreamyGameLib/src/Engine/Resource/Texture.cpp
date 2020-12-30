#include "Engine/Resource/Texture.hpp"

#include "Engine/Resource/ResourceManager.hpp"
#include "Resource/TextureResource.hpp"

namespace creamyLib::engine::resource
{
    void Texture::disposeMemory()
    {
        getResource().destroy();
    }

    Texture::Texture(const impl::resource::TextureResource& texture): Resource(std::make_any<impl::resource::TextureResource>(texture))
    {
        
    }

    impl::resource::TextureResource Texture::getResource()
    {
        return std::any_cast<impl::resource::TextureResource>(Resource::getResource());
    }

    void Texture::destroy()
    {
        ResourceManager::getInstance()->removeResource(this);
    }
}
