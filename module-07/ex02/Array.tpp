template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw()
{
    return ("Index Out Of Bounds Exception!!!!");
}

// Constructors and Destructor
template <typename T>
Array<T>::Array()
{
    std::cout << "Array default Constructor called" << std::endl;
    this->_size = 1;
    this->_arr = new T[this->_size];
}

template <typename T>
Array<T>::Array(unsigned int num) 
{
    std::cout << "Array Constructor called" << std::endl;
    this->_size = num;
    this->_arr = new T[this->_size + 1];
}

template <typename T>
Array<T>::~Array() 
{
    std::cout << "Array Destructor called" << std::endl;
    delete[] this->_arr;
}

// Canonical form
template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &obj) 
{
    if (this == &obj)
        return *this;
    delete[] this->_arr;
    this->_size = obj.size();
    this->_arr = new T[this->_size];
    for (unsigned int i=0; i < this->_size; i++)
        this->_arr[i] = obj._arr[i];
    return *this;
}

template <typename T>
T   &Array<T>::operator[](unsigned int index)
{
    if (index >= this->_size)
        throw IndexOutOfBoundsException();
    return (this->_arr[index]);
}

template <typename T>
Array<T>::Array(const Array &obj) 
{
    this->_arr = new T[1];
    *this = obj;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return this->_size;
}
