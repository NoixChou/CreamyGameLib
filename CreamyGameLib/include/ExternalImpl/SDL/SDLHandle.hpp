#pragma once

struct SDL_Window;
struct SDL_Renderer;

namespace creamyLib::impl
{
    struct LibHandle
    {
        SDL_Window* const sdlWindow;
        SDL_Renderer* const sdlRenderer;
    };

    using LibHandlePointer = LibHandle*;
}
