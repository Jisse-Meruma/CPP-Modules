#include "Span.hpp"
#include <limits>

const char *Span::ArrayFullException::what(void) const throw()
{
    return ("Array Is Full! Exception!");
}

const char *Span::CantCalculateSpanException::what(void) const throw()
{
    return ("Need At least 2 numbers in array to calculate Span! Exception!!!");
}
// Constructors and Destructor
Span::Span() {
    std::cout << "Span default Constructor called" << std::endl;
    this->_numbers.resize(1);
    this->_total_stored = 0;
}

Span::Span(unsigned int number) {
    std::cout << "Span Constructor called" << std::endl;
    this->_numbers.resize(number);
    this->_total_stored = 0;
}

Span::~Span() {
    std::cout << "Span Destructor called" << std::endl;
}

// Canonical form
Span &Span::operator=(const Span &obj) {
    (void)obj;
    return *this;
}

Span::Span(const Span &obj) {
    *this = obj;
}

void Span::addNumber(int integer)
{
    if (this->_total_stored + 1 == this->_numbers.size())
        throw ArrayFullException();
    this->_numbers.assign(this->_total_stored, integer);
    this->_sorted.insert(integer);
    this->_total_stored++;
}

unsigned int Span::longestSpan(void)
{
    if (this->_numbers.size() < 2)
        throw CantCalculateSpanException();
    return (*(this->_sorted.rbegin()) - *(this->_sorted.begin()));
}

int Span::shortestSpan(void)
{
    unsigned int range = std::numeric_limits<unsigned int>::max();
    unsigned int previous;
    std::multiset<int>::iterator it = this->_sorted.begin();

    if (this->_numbers.size() < 2)
        throw CantCalculateSpanException();
    for (; it != this->_sorted.end(); previous = *it, it++)
    {
        if (*it - previous < range)
            range = *it - previous;
    }
    return (range);
}

