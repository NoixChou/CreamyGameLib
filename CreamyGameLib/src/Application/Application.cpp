#include "Application/Application.hpp"

#include <iostream>

#include "Application/ApplicationConfig.hpp"

#include "ExternalImpl/SDL/SDLConfig.hpp"
#include "ExternalImpl/SDL/Initializer.hpp"
#include "ExternalImpl/SDL/Finalizer.hpp"
#include "ExternalImpl/SDL/SDLEvent.hpp"
#include "ExternalImpl/SDL/SDLRender.hpp"

#include "Exception/Application/InitializationFailedException.hpp"

#include "Engine/Time/DeltaTime.hpp"

namespace creamyLib
{
    Application::Application(impl::SDLHandlePointer sdlHandle) : sdlHandle(sdlHandle)
    {
    }

    Application Application::Create(const ApplicationConfig& applicationConfig)
    {
        auto l_Result = impl::Initialize(impl::SDLConfig{ applicationConfig.applicationTitle, 100, 100, applicationConfig.windowWidth, applicationConfig.windowHeight, 0 });

        if(!l_Result.isSucceed)
        {
            throw exception::InitializationFailedException(l_Result.description);
        }

        return Application(l_Result.sdlHandle);
    }

    void Application::Start(engine::World* startWorld)
    {
        std::cout << "Application started" << std::endl;

        while(isRunning)
        {
            impl::SDLEvent::Process();

            engine::DeltaTime::Update();
            impl::ClearBuffer(sdlHandle);

            float deltaTime = engine::DeltaTime::Get();
            startWorld->Update(deltaTime);

            impl::PresentBuffer(sdlHandle);

            isRunning = !impl::SDLEvent::IsQuit();
        }

        startWorld->Destroy();
    }

    void Application::Quit()
    {
        impl::Finalize(this->sdlHandle);
    }
}
