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
			std::cout << "n : " << n << std::endl;
			std::cout << "_size : " << _size << std::endl;
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
		{ delete[] _array;}

		Array &operator=(Array const & src)
		{
			std::cout << "Operator= called" << std::endl;
			if ( this != &src )
			{
				_size = src.size();
				if (_array != NULL)
					delete[]_array;
				_array = new T[_size];
				std::cout << "Array has now " << _size << " empty spaces." << std::endl;
				for (int i = 0; i < _size ; i++)
					_array[i] = src._array[i];
			}
			return ( *this );
		}

		T& operator[] (unsigned int index)
		{
			if (index < 0 || index >= _size)
				throw std::exception();
			return (_array[index]);
		}

		const T& operator[] (unsigned int index) const
		{
			if (index < 0 || index >= _size)
				throw std::exception();
			return (_array[index]);
		}

		int size(void) const { return _size; }

	private :
		T * _array;
		unsigned int _size;

};

#endif
