#pragma once

#ifdef CREAMY_INTERNAL_LIB
#ifdef CREAMY_USE_DXLIB

#else
    #define CREAMY_USE_SDL
    #pragma comment(lib, "SDL2.lib")
    #pragma comment(lib, "SDL2main.lib")
#endif
#endif

#include "Config.hpp"
#include "Finalizer.hpp"
#include "Initializer.hpp"
#include "Handle.hpp"
#include "Event.hpp"
#include "Render.hpp"
#include "Input.hpp"
