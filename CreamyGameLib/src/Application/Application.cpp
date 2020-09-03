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
    Application::Application(const impl::LibHandlePointer libHandle) : libHandle(libHandle)
    {
        engine::resource::ResourceManager::Initialize(libHandle);
    }

    Application Application::Create(const ApplicationConfig& applicationConfig)
    {
        auto* l_LibHandle = impl::Initialize(impl::LibConfig{ applicationConfig.applicationTitle, 100, 100, applicationConfig.windowWidth, applicationConfig.windowHeight, 0 });

        if(!l_LibHandle)
        {
            throw exception::InitializationFailedException();
        }

        engine::resource::ResourceManager::Initialize(l_LibHandle);

        return Application(l_LibHandle);
    }

    void Application::Start(engine::World* startWorld)
    {
        engine::DeltaTime::Init();

        std::cout << "Application started" << std::endl;

        while(isRunning)
        {
            impl::WindowEvent::Process();

            engine::DeltaTime::Update();
            const float l_DeltaTime = engine::DeltaTime::Get();
            startWorld->Update(l_DeltaTime);

            impl::RenderService::PresentBuffer(libHandle);

            isRunning = !impl::WindowEvent::IsQuit();
        }
    }

    void Application::Quit() const
    {
        engine::resource::ResourceManager::Finalize();

        impl::Finalize(libHandle);
    }

    impl::LibHandlePointer Application::GetLibHandle() const
    {
        return libHandle;
    }
}
