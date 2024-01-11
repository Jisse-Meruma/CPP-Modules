#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <limits>
#include <chrono>

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
    void checkForDuplicates(void);

    template<typename T>
    void PrintArray(T array);

    template<typename T, typename T2>
    int ParsePairArray(T array, T2 &pair_array);

    template<typename T>
    void BigSort(T it_begin, T it_end);

    template<typename T>
    void MergeSort(T it_begin, T it_end, std::ptrdiff_t distance);

    template<typename T, typename T2>
    void SmallSort(T pair_array, T2 &Array, int struggler);

    template<typename T>
    T JacobBuilder(size_t size);

    void sort(void);
    void sort_vector(void);
    void sort_deque(void);

    

private:
    std::vector<int> _vec;
    std::deque<int> _deq;
    double _vectime;
    double _dequetime;
};


void error_message(void);

#endif
