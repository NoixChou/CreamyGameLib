#pragma once

namespace creamyLib::impl
{
    class WindowEvent
    {
    private:
        static bool isQuit;

    public:
        static void Process();
        static bool IsQuit();
    };
}
