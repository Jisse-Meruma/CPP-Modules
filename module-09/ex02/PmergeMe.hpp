#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <limits>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(char *argv[]);
    ~PmergeMe();

    // Copy constructor
    PmergeMe(const PmergeMe &obj);
    // Operator overload
    PmergeMe &operator=(const PmergeMe &obj);

    bool IsValidNumber(char *numb);

    template<typename T>
    void PrintArray(T array);
    void sort(void);
    void sort_vector(void);
    void sort_deque(void);

    

private:
    std::vector<int> _vec;
    std::deque<int> _deq;
};


void error_message(void);

#endif
