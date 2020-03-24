#pragma once

struct SDL_Window;
struct SDL_Renderer;

namespace creamyLib::impl
{
    struct SDLHandle
    {
        SDL_Window* const sdlWindow;
        SDL_Renderer* const sdlRenderer;
    };

    using SDLHandlePointer = SDLHandle*;
}
