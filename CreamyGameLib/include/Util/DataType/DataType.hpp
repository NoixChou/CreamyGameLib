#pragma once

#include <cstddef>
#include <string>
#include <typeinfo>

namespace creamyLib::typeInfo
{
    class DataType
    {
    private:
        std::size_t typeHash_;
        std::size_t typeSize_;

        explicit DataType(std::size_t typeHash, std::size_t typeSize);

        static std::size_t generateTypeHash(const std::type_info& type)
        {
            std::size_t hash = 14695981039346656037U;

            std::string_view typeName = type.name();
            for (auto char_ : typeName)
            {
                hash ^= char_;
                hash *= 1099511628211LLU;
            }

            return hash;
        }

    public:
        template<typename Type>
        [[nodiscard]] static DataType make()
        {
            return DataType(generateTypeHash(typeid(Type)), sizeof(Type));
        }

        [[nodiscard]] static DataType make(std::size_t typeHash, std::size_t typeSize);

        [[nodiscard]] std::size_t getHash() const;
        [[nodiscard]] std::size_t getSize() const;

        bool operator==(const DataType& rhs) const;
        bool operator!=(const DataType& rhs) const;
    };
}
