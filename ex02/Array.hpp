#ifndef ARRY_HPP
# define ARRY_HPP

template< typename T>
class Array
{
private:
    T*  _array;
	unsigned int	_size;
public:
    Array(): _size(0)
	{
		this->_array = new T[this->_size];
	}
    Array(unsigned int size): _size(size)
    {
           this->_array = new T[this->_size];
    }
    Array(const Array &src): _size(src.size())
	{
		this->_array = NULL;
		*this = src;
	}
    ~Array()
    {
        if (this->_array)
            delete [] this->_array;
    }
    Array &operator=(const Array &src)
    {
        if (this != &src)  
        {
            if (this->_array != NULL)
                delete[] this->_array;
            this->_size = src._size; 
            this->_array = new T[src._size]; 
            for (unsigned int i = 0; i < this->_size; i++) 
                this->_array[i] = src._array[i];
        }
        return *this;
    }
    T &operator[](unsigned int index)
    {
    	if (index >= this->_size) {
			throw Array::InvalidIndexException();
		}
        return this->_array[index];
    }

	class	InvalidIndexException : public std::exception
	{
	public:
		virtual const char	*what() const throw();
	};


    unsigned int	size(void) const {
	    return (this->_size);
	}
    const std::string	getType(void) const {
		return (typeid(this->arr_).name());
	}
};

template< typename T >
const char	*Array<T>::InvalidIndexException::what() const throw()
{
	return ("Error: Invalid index");
}
#endif