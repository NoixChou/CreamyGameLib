#pragma once

#ifdef CREAMY_USE_DXLIB

#else
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#include "ExternalImpl/SDL/SDLConfig.hpp"
#include "ExternalImpl/SDL/SDLFinalizer.hpp"
#include "ExternalImpl/SDL/SDLInitializer.hpp"
#include "ExternalImpl/SDL/SDLHandle.hpp"
#include "ExternalImpl/SDL/SDLEvent.hpp"
#include "ExternalImpl/SDL/SDLRender.hpp"
#include "ExternalImpl/SDL/SDLInput.hpp"
#endif

/*namespace creamyLib::internal
{
    class ExternalLib
    {
    public:
        static impl::LibHandlePointer Initialize(const impl::LibConfig& config);
        static void Finalize(impl::LibHandlePointer libHandle);
    };

}
*/
