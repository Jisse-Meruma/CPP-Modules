#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>


struct Data
{
    int numb;
    char charactar;
    double pointy_number;
};



class Serializer {
public:
    uintptr_t   serialize(Data* ptr);
    Data*       deserialize(uintptr_t raw);

private:
    Serializer();
    Serializer(std::string);
    ~Serializer();
    // Copy constructor
    Serializer(const Serializer &obj);
    // Operator overload
    Serializer &operator=(const Serializer &obj);
};

#endif
