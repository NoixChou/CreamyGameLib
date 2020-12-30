#pragma once

#include "ApplicationConfig.hpp"

#include "../../InternalLib/include/ExternalLibrary.hpp"

namespace creamyLib
{
    namespace engine {
        class World;
    }

    class Application
    {
    private:
        impl::LibHandlePointer libHandle_;

        bool isRunning_ = true;

        Application(impl::LibHandlePointer libHandle);

    public:
        static Application create(const ApplicationConfig& applicationConfig);

        void start(engine::World* startWorld);
        void quit() const;

        [[nodiscard]] impl::LibHandlePointer getLibHandle() const;
    };
}
