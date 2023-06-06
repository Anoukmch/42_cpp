#ifndef ARRAY_H
#define ARRAY_H

# include <iostream>
# include <iomanip>
# include <string>

template <typename T>
class Array
{
	public :
		Array()
		{
			std::cout << "Default constructor called" << std::endl;
			_size = 0;
			_array = new T[0];
			std::cout << "Array has now 0 space.\n" << std::endl;
		}

		Array(unsigned int n) : _size(n)
		{
			if (_size < 0 || _size > INT_MAX)
				throw std::exception();
			std::cout << "Overload constructor called" << std::endl;
			_size = n;
			_array = new T[n];
			std::cout << "Array has now " << _size << " spaces.\n" << std::endl;
		}

		Array(Array const & src) : _array(NULL), _size(0)
		{
			std::cout << "Copy constructor called" << std::endl;
			*this = src;
		}

		~Array(void)
		{
			std::cout << "Destructor called" << std::endl;
			delete[] _array;
		}

		Array &operator=(Array const & src)
		{
			std::cout << "Operator = called" << std::endl;
			if ( this != &src )
			{
				_size = src.size();
				if (_array != NULL) //Test to send an array != NULL
					delete[]_array;
				_array = new T[_size]; // Try that (every obj are different or the same?) Try : _array = new Brain(*src._array)[_size];
				std::cout << "Array has now " << _size << " empty spaces." << std::endl;
				for (int i = 0; i < _size ; i++)
					_array[i] = src._array[i]; // What if class doesn't have = operator ? // _array[i] = src[i]; --> would it work ? // new (&_array[i]) T(src._array); <- this line is ok ?
			}
			return ( *this );
		}

		T& operator[] (int index)
		{
			if (index < 0 || index >= _size)
				throw std::exception();
			return (_array[index]);
		}

		const T& operator[] (int index)
		{
			if (index < 0 || index >= _size)
				throw std::exception();
			return (_array[index]);
		}

		int size(void) const { return _size; }

	private :
		T * _array;
		int _size;

};

#endif
