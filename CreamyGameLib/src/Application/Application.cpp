#include "Application/Application.hpp"

#include <iostream>

#include "DrawResource.hpp"
#include "Application/ApplicationConfig.hpp"
#include "Engine/World/World.hpp"

#include "../../InternalLib/include/ExternalLibrary.hpp"

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
        auto* libHandle = impl::Initialize(impl::LibConfig{ applicationConfig.applicationTitle, 100, 100, applicationConfig.windowWidth, applicationConfig.windowHeight, 0 });

        if(!libHandle)
        {
            throw exception::InitializationFailedException();
        }

        engine::resource::ResourceManager::initialize(libHandle);

        return Application(libHandle);
    }

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
