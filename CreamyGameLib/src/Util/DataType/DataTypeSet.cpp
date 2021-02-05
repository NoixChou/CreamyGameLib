#include "Util/DataType/DataTypeSet.hpp"

#include <algorithm>
#include <functional>

namespace creamyLib::typeInfo
{
    void DataTypeSet::addType(const DataType& type)
    {
        types_.emplace_back(type);
        memorySize_ += type.getSize();
    }

    std::size_t DataTypeSet::getMemorySize() const
    {
        return memorySize_;
    }

    std::size_t DataTypeSet::getSize() const
    {
        return types_.size();
    }

    std::size_t DataTypeSet::getOffset(const DataType& type) const
    {
        std::size_t offset = 0;

        for (auto&& data : types_)
        {
            if(data == type)
            {
                return offset;
            }

            offset += data.getSize();
        }

        return offset;
    }

    bool DataTypeSet::operator==(const DataTypeSet& rhs) const
    {
        if(memorySize_ != rhs.memorySize_)
        {
            return false;
        }

        for (std::size_t i = 0; i < types_.size(); i++)
        {
            if(types_[i] != rhs.types_[i])
            {
                return false;
            }
        }

        return true;
    }

    bool DataTypeSet::operator!=(const DataTypeSet& rhs) const
    {
        return !(*this == rhs);
    }

    bool DataTypeSet::contains(const DataTypeSet& typeSet) const
    {
        for (auto&& type : typeSet.types_)
        {
            bool isFound = false;
            for (auto&& myType : types_)
            {
                isFound |= myType == type;
                if (isFound) break;
            }

            if (!isFound)
            {
                return false;
            }
        }

        return true;
    }

    bool DataTypeSet::contains(const DataType& type)
    {
        return std::ranges::any_of(types_, [type](const DataType& myType) { return myType == type; });
    }

    std::vector<DataType>::iterator DataTypeSet::begin()
    {
        return types_.begin();
    }

    std::vector<DataType>::iterator DataTypeSet::end()
    {
        return types_.end();
    }
}
