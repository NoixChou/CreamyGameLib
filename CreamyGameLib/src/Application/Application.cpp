#include "Application/Application.hpp"

#include <iostream>

#include "Application/ApplicationConfig.hpp"

#include "ExternalImpl/ExternalLibrary.hpp"

#include "Exception/Application/InitializationFailedException.hpp"

#include "Engine/Time/DeltaTime.hpp"

namespace creamyLib
{
    Application::Application(const impl::LibHandlePointer libHandle) : libHandle(libHandle)
    {
    }

    Application Application::Create(const ApplicationConfig& applicationConfig)
    {
        auto l_LibHandle = impl::Initialize(impl::LibConfig{ applicationConfig.applicationTitle, 100, 100, applicationConfig.windowWidth, applicationConfig.windowHeight, 0 });

        if(!l_LibHandle)
        {
            throw exception::InitializationFailedException();
        }

        return Application(l_LibHandle);
    }

    void Application::Start(engine::World* startWorld)
    {
        std::cout << "Application started" << std::endl;

        while(isRunning)
        {
            impl::WindowEvent::Process();

            engine::DeltaTime::Update();
            impl::RenderService::ClearBuffer(libHandle);

            float deltaTime = engine::DeltaTime::Get();
            startWorld->Update(deltaTime);

            impl::RenderService::PresentBuffer(libHandle);

            isRunning = !impl::WindowEvent::IsQuit();
        }

        startWorld->Destroy();
    }

    void Application::Quit()
    {
        impl::Finalize(this->libHandle);
    }
}
