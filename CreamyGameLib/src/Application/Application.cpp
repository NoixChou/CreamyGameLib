#include "Application/Application.hpp"

#include <iostream>

#include "Application/ApplicationConfig.hpp"
#include "Engine/World/World.hpp"

#include "../../InternalLib/include/ExternalLibrary.hpp"

#include "Exception/Application/InitializationFailedException.hpp"

#include "Engine/Time/DeltaTime.hpp"
#include "Util/Color.hpp"

namespace creamyLib
{
    Application::Application(const impl::LibHandlePointer libHandle) : libHandle(libHandle)
    {
    }

    Application Application::Create(const ApplicationConfig& applicationConfig)
    {
        auto* l_LibHandle = impl::Initialize(impl::LibConfig{ applicationConfig.applicationTitle, 100, 100, applicationConfig.windowWidth, applicationConfig.windowHeight, 0 });

        if(!l_LibHandle)
        {
            throw exception::InitializationFailedException();
        }

        return Application(l_LibHandle);
    }

    void Application::Start(engine::World* startWorld)
    {
        std::cout << "Application started" << std::endl;

        engine::DeltaTime::Init();

        while(isRunning)
        {
            impl::WindowEvent::Process();

            impl::RenderService::ClearBuffer(libHandle, Color(255, 255, 255));

            engine::DeltaTime::Update();
            const float l_DeltaTime = engine::DeltaTime::Get();
            startWorld->Update(l_DeltaTime);

            impl::RenderService::PresentBuffer(libHandle);

            isRunning = !impl::WindowEvent::IsQuit();
        }
    }

    void Application::Quit() const
    {
        impl::Finalize(this->libHandle);
    }

    impl::LibHandlePointer Application::GetLibHandle() const
    {
        return libHandle;
    }
}
