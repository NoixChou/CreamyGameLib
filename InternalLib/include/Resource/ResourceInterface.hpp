#pragma once

namespace creamyLib::impl::resource
{
    class ResourceInterface
    {
    private:
        bool isAvailable = false;

    public:
        virtual ~ResourceInterface() = default;
        virtual void Destroy() = 0;
    };
}
