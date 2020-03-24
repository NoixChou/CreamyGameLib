#include "Engine/Actor/Component/Component.hpp"

namespace creamyLib::engine
{
    Component::Component(Actor* owner, int updatePriority) : owner(owner), updatePriority(updatePriority)
    {
        
    }
}
