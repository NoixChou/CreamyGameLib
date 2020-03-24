#pragma once

#include "ApplicationConfig.hpp"

#include "ExternalImpl/SDL/SDLHandle.hpp"

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

        void Start();
        void Quit();
    };
}
