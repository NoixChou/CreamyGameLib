#include "Application/Application.hpp"

int main(int argc, char** argv)
{
    auto game = creamyLib::Application::Create(creamyLib::ApplicationConfig{ "TestGame", 1024, 768 });

    auto world = new creamyLib::engine::World(&game, creamyLib::engine::WorldConfiguration{});
    auto scene = new creamyLib::engine::Scene(world);
    auto actor = new creamyLib::engine::Actor(scene);

    game.Start(world);
    game.Quit();

    delete actor;
    delete scene;
    delete world;

    return 0;
}
