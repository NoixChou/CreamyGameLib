#pragma once

#include <vector>

#include "Texture.hpp"
#include "../../InternalLib/include/ExternalLibrary.hpp"

namespace creamyLib::engine::resource
{
    class ResourceManager
    {
    private:
        static ResourceManager* instance;
        static impl::LibHandlePointer libHandle;

        ResourceManager(impl::LibHandlePointer libHandle);
        ~ResourceManager();

        static void Initialize(impl::LibHandlePointer libHandle);
        static void Finalize();

        std::vector<Resource*> resources;

        friend class Application;

    public:
        static ResourceManager* GetInstance();
        void RemoveResource(Resource* resource);
        Texture* GetResourceTextureFromFile(const std::string& fileName);
    };
}
