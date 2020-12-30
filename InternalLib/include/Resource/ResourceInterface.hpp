#pragma once

namespace creamyLib::impl::resource
{
    class ResourceInterface
    {
    private:
        bool isAvailable_ = false;

    public:
        virtual ~ResourceInterface() = default;
        virtual void destroy() = 0;
    };
}
