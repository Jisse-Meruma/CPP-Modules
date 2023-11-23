#include "Serializer.hpp"

// Constructors and Destructor
Serializer::Serializer() {
    std::cout << "Serializer default Constructor called" << std::endl;
}

Serializer::~Serializer() {
    std::cout << "Serializer Destructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &obj) {
    (void)obj;
    return *this;
}

Serializer::Serializer(const Serializer &obj) {
    *this = obj;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*   Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}
