#include "Util/DataType/DataType.hpp"

namespace creamyLib::typeInfo
{
    DataType::DataType(std::size_t typeHash, std::size_t typeSize): typeHash_(typeHash), typeSize_(typeSize)
    {
    }

    DataType DataType::make(std::size_t typeHash, std::size_t typeSize)
    {
        return DataType(typeHash, typeSize);
    }

    std::size_t DataType::getHash() const
    {
        return typeHash_;
    }

    std::size_t DataType::getSize() const
    {
        return typeSize_;
    }

    bool DataType::operator==(const DataType& rhs) const
    {
        return typeHash_ == rhs.typeHash_;
    }

    bool DataType::operator!=(const DataType& rhs) const
    {
        return !(*this == rhs);
    }
}
