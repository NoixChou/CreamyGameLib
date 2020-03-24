#pragma once

#include "ApplicationConfig.hpp"

#include "ExternalImpl/SDL/SDLHandle.hpp"
#include "Engine/World/World.hpp"

namespace creamyLib
{
    class Application
    {
    private:
        impl::SDLHandlePointer sdlHandle;

        bool isRunning = true;

        Application(impl::SDLHandlePointer sdlHandle);

    public:
        static Application Create(const ApplicationConfig& applicationConfig);

        void Start(engine::World* startWorld);
        void Quit();
    };
}
