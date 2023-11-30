#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>

class Span {
public:

    class ArrayFullException : public std::exception
    {  
        virtual const char *what(void) const throw();
    };

    class CantCalculateSpanException : public std::exception
    {  
        virtual const char *what(void) const throw();
    };


    Span();
    Span(unsigned int Number);
    ~Span();

    // Copy constructor
    Span(const Span &obj);
    // Operator overload
    Span &operator=(const Span &obj);

    void    addNumber(int integer);
    int     shortestSpan(void);
    unsigned int longestSpan(void);

    template<typename Iterator>
    void    AddRange(Iterator begin, Iterator end)
    {
        int distance;

        distance = std::distance(begin, end);
        if (distance < 0)
            throw std::range_error("Range Error Negative Distance! Excpetion");
        if (distance + _total_stored > this->_numbers.size())
            throw std::range_error("Range too big for Span. try adding less number or create a bigger SPAN!");
        for (; begin != end; begin++)
        {
            this->_numbers.assign(this->_total_stored, *begin);
            this->_sorted.insert(*begin);
            this->_total_stored++;
        }
    }

private:
    std::vector<int> _numbers;
    std::multiset<int> _sorted;

    unsigned int _total_stored;
};

#endif
