#include "Application/Application.hpp"

int main(int argc, char** argv)
{
    auto game = creamyLib::Application::Create(creamyLib::ApplicationConfig{ "TestGame", 1024, 768 });

    game.Quit();
    return 0;
}