#include "Application/Application.hpp"
#include "Application/ApplicationConfig.hpp"

#include "ExternalImpl/SDL/SDLConfig.hpp"
#include "ExternalImpl/SDL/Initializer.hpp"
#include "ExternalImpl/SDL/Finalizer.hpp"

#include "Exception/Application/InitializationFailedException.hpp"

namespace creamyLib
{
    Application::Application(impl::SDLHandlePointer sdlHandle) : sdlHandle(sdlHandle)
    {
    }

    Application Application::Create(const ApplicationConfig& applicationConfig)
    {
        auto l_Result = impl::Initialize(impl::SDLConfig{ applicationConfig.applicationTitle, 0, 0, applicationConfig.windowWidth, applicationConfig.windowHeight, 0 });

        if(!l_Result.isSucceed)
        {
            throw exception::InitializationFailedException(l_Result.description);
        }

        return Application(l_Result.sdlHandle);
    }

    void Application::Quit()
    {
        impl::Finalize(this->sdlHandle);
    }
}
