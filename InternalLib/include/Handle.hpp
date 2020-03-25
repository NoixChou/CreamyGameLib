#pragma once

#ifdef CREAMY_USE_SDL
struct SDL_Window;
struct SDL_Renderer;
#endif

namespace creamyLib::impl
{
    struct LibHandle
    {
#ifdef CREAMY_USE_DXLIB

#endif
#ifdef CREAMY_USE_SDL
        SDL_Window* const sdlWindow;
        SDL_Renderer* const sdlRenderer;
#endif
    };

    using LibHandlePointer = LibHandle*;
}
