#pragma once

#include "Util/DataType/DataTypePool.hpp"
#include "Util/DataType/DataTypeSet.hpp"

namespace creamyLib::engine::ecs
{
    class ComponentGroup
    {
    private:
        typeInfo::DataTypeSet groupType_;
        typeInfo::DataTypePool componentPool_;

    public:
        ComponentGroup(typeInfo::DataTypeSet groupType, std::size_t capacity);

        
    };
}
