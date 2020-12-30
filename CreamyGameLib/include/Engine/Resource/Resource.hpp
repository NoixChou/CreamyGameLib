#pragma once

#include <any>

namespace creamyLib::engine::resource
{
    class Resource
    {
    private:
        std::any resource_;

        virtual void disposeMemory() = 0;

        friend class ResourceManager;

    protected:
        std::any& getResource();

    public:
        Resource(std::any resource);
        virtual ~Resource();
        Resource(const Resource&) = default;
        Resource& operator=(const Resource&) = default;
        Resource(Resource&&) = default;
        Resource& operator=(Resource&&) = default;

        virtual void destroy() = 0;
    };
}
