#include "Engine/Resource/ResourceManager.hpp"

#include <iostream>

#include "Exception/Resource/ResourceLoadFailedException.hpp"
#include "Resource/ResourceLoader.hpp"

namespace creamyLib::engine::resource
{
    ResourceManager* ResourceManager::instance = nullptr;
    impl::LibHandlePointer ResourceManager::libHandle = nullptr;

    ResourceManager::ResourceManager(impl::LibHandlePointer libHandle)
    {
        ResourceManager::libHandle = libHandle;
    }

    ResourceManager::~ResourceManager()
    {
        for(auto* l_Resource : resources)
        {
            l_Resource->Destroy();
            delete l_Resource;
        }

        resources.clear();
    }

    void ResourceManager::Initialize(impl::LibHandlePointer libHandle)
    {
        if(!instance)
        {
            instance = new ResourceManager(libHandle);
        }
    }

    void ResourceManager::Finalize()
    {
        if (!instance) return;

        delete instance;
    }

    ResourceManager* ResourceManager::GetInstance()
    {
        return instance;
    }

    void ResourceManager::RemoveResource(Resource* resource)
    {
        if (!resource) return;

        const auto l_Iterator = std::find(resources.begin(), resources.end(), resource);

        if (l_Iterator != resources.end())
        {
            resource->DisposeMemory();
            resources.erase(l_Iterator);
        }
    }

    Texture* ResourceManager::GetResourceTextureFromFile(const std::string& fileName)
    {
        auto l_Result = impl::resource::LoadTextureFromFile(ResourceManager::libHandle, fileName);
        if(!l_Result)
        {
            throw exception::ResourceLoadFailedException(fileName, "");
        }

        auto* l_Texture = new Texture(l_Result.value());

        resources.emplace_back(l_Texture);

        return l_Texture;
    }
}
