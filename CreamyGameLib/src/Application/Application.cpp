#include "Application/Application.hpp"

#include <iostream>

#include "../../../External/SDL/include/SDL_video.h"

#include "../../InternalLib/include/ExternalLibrary.hpp"
#include "../../InternalLib/include/DrawResource.hpp"

#include "Application/ApplicationConfig.hpp"
#include "Engine/World/World.hpp"
#include "Engine/Entity/World.hpp"

#include "Exception/Application/InitializationFailedException.hpp"

#include "Engine/Time/DeltaTime.hpp"
#include "Engine/Resource/ResourceManager.hpp"

namespace creamyLib
{
    Application::Application(const impl::LibHandlePointer libHandle) : libHandle_(libHandle)
    {
        engine::resource::ResourceManager::initialize(libHandle);
    }

    Application Application::create(const ApplicationConfig& applicationConfig)
    {
        std::uint32_t windowFlags = 0;

        if(applicationConfig.isFullscreen)
        {
            windowFlags |= SDL_WINDOW_FULLSCREEN;
        }

        auto* libHandle = impl::Initialize(impl::LibConfig{ applicationConfig.applicationTitle, 100, 100, applicationConfig.windowWidth, applicationConfig.windowHeight, windowFlags});

        if(!libHandle)
        {
            throw exception::InitializationFailedException();
        }

        engine::resource::ResourceManager::initialize(libHandle);
        //engine::resource::AssetManager::initialize(libHandle);

        return Application(libHandle);
    }

    /*
    void Application::start(engine::World* startWorld)
    {
        engine::DeltaTime::init();

        std::cout << "Application started" << std::endl;

        while(isRunning_)
        {
            impl::WindowEvent::process();

            engine::DeltaTime::update();
            const float deltaTime = engine::DeltaTime::get();
            startWorld->update(deltaTime);

            impl::RenderService::presentBuffer(libHandle_);

            isRunning_ = !impl::WindowEvent::isQuit();
        }
    }
    */

    void Application::start(engine::ecs::World* startWorld)
    {
        engine::DeltaTime::init();

        std::cout << "Application (ECS) started" << std::endl;

        while (isRunning_)
        {
            impl::WindowEvent::process();

            engine::DeltaTime::update();
            startWorld->update();

            impl::RenderService::presentBuffer(libHandle_);

            isRunning_ = !impl::WindowEvent::isQuit();
        }
    }

    void Application::quit() const
    {
        engine::resource::ResourceManager::finalize();

        impl::Finalize(libHandle_);
    }

    impl::LibHandlePointer Application::getLibHandle() const
    {
        return libHandle_;
    }
}
