#pragma once

#include "ApplicationConfig.hpp"

#include "ExternalImpl/ExternalLibrary.hpp"
#include "Engine/World/World.hpp"

namespace creamyLib
{
    class Application
    {
    private:
        impl::LibHandlePointer libHandle;

        bool isRunning = true;

        Application(impl::LibHandlePointer libHandle);

    public:
        static Application Create(const ApplicationConfig& applicationConfig);

        void Start(engine::World* startWorld);
        void Quit();
    };
}
