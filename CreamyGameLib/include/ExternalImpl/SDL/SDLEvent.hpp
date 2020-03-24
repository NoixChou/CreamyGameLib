#pragma once

namespace creamyLib::impl
{
    class SDLEvent
    {
    private:
        static bool isQuit;

    public:
        static void Process();
        static bool IsQuit();
    };
}
