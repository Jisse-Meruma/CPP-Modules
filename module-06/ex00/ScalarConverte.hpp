#ifndef SCALARCONVERTE_HPP
#define SCALARCONVERTE_HPP

#include <iostream>
#include <string>

typedef enum
{
    NO_TYPE,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
}   t_type;

class ScalarConverte {
    public:
        static void convert(const std::string &input);
    private:
        ScalarConverte();
        ScalarConverte(std::string n);
        ScalarConverte(const ScalarConverte &obj);
        ~ScalarConverte();
        ScalarConverte &operator=(const ScalarConverte &obj);
};

typedef void (*t_func)(const std::string &);

#endif
