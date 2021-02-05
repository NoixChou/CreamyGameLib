#include <utility>

#include "Engine/Entity/ComponentGroup.hpp"

namespace creamyLib::engine::ecs
{
    ComponentGroup::ComponentGroup(typeInfo::DataTypeSet groupType, std::size_t capacity) : groupType_(std::move(groupType)), componentPool_(groupType_, capacity)
    {}
}
