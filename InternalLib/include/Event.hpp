#pragma once

namespace creamyLib::impl
{
    class WindowEvent
    {
    private:
        static bool isQuit_;

    public:
        static void process();
        static bool isQuit();
    };
}
