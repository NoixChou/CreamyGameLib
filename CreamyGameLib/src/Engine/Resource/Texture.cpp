#include "Engine/Resource/Texture.hpp"

#include "Engine/Resource/ResourceManager.hpp"
#include "Resource/TextureResource.hpp"

namespace creamyLib::engine::resource
{
    void Texture::DisposeMemory()
    {
        GetResource().Destroy();
    }

    Texture::Texture(const impl::resource::TextureResource& texture): Resource(std::make_any<impl::resource::TextureResource>(texture))
    {
        
    }

    impl::resource::TextureResource Texture::GetResource()
    {
        return std::any_cast<impl::resource::TextureResource>(Resource::GetResource());
    }

    void Texture::Destroy()
    {
        ResourceManager::GetInstance()->RemoveResource(this);
    }
}
