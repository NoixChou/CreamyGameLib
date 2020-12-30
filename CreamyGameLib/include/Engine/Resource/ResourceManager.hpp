#pragma once

#include <vector>

#include "Texture.hpp"
#include "../../InternalLib/include/ExternalLibrary.hpp"

namespace creamyLib::engine::resource
{
    class ResourceManager
    {
    private:
        static ResourceManager* instance_;
        static impl::LibHandlePointer libHandle_;

        ResourceManager(impl::LibHandlePointer libHandle);
        ~ResourceManager();

        static void initialize(impl::LibHandlePointer libHandle);
        static void finalize();

        std::vector<Resource*> resources_;

        friend class Application;

    public:
        static ResourceManager* getInstance();
        void removeResource(Resource* resource);
        Texture* getResourceTextureFromFile(const std::string& fileName);
    };
}
