#pragma once

#include <any>

namespace creamyLib::engine::resource
{
    class Resource
    {
    private:
        std::any resource_;

    protected:
        [[nodiscard]] std::any& getRawResource();

    public:
        Resource(std::any resource);
        virtual ~Resource() = default;
        Resource(const Resource&) = default;
        Resource& operator=(const Resource&) = default;
        Resource(Resource&&) = default;
        Resource& operator=(Resource&&) = default;

        virtual void destroy() = 0;
    };
}
