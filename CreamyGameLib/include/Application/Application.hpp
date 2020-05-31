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
        impl::LibHandlePointer libHandle;

        bool isRunning = true;

        Application(impl::LibHandlePointer libHandle);

    public:
        static Application Create(const ApplicationConfig& applicationConfig);

        void Start(engine::World* startWorld);
        void Quit() const;

        [[nodiscard]] impl::LibHandlePointer GetLibHandle() const;
    };
}
