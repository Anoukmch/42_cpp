#include "Scalar.hpp"
#include <cstdlib>
#include <string>

ScalarConverter::ScalarConverter() : _char(0), _int(0), _float(0), _double(0) {}

ScalarConverter::ScalarConverter( ScalarConverter const & src) {
	*this = src;
}

// Destructors
ScalarConverter::~ScalarConverter( void ) {
}

// Operator overload
ScalarConverter & ScalarConverter::operator=( ScalarConverter const & src) {
	if ( this != &src ) {
		_char = src._char;
		_int = src._int;
		_float = src._float;
		_double = src._double;
	}
	return ( *this );
}

void ScalarConverter::convert(std::string const& input)
{
	// Conversion to the native type
	if (input.size() == 1 && std::isprint(input[0])) {
		this->isChar(input);
		this->printer();
		return ;
	}
	else if (input[input.length() - 1] == 'f')
	{
		this->isFloat(input);
		this->printer();
		return ;
	}
	else // double, int
	{
		_double = static_cast<double>(std::atof(input.c_str()));
		_int =  static_cast<int>(std::atoi(input.c_str()));
	}
}

void	ScalarConverter::printer(void) {
	std::cout << "char: " << _char << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << std::endl;
	std::cout << "double: " << _double << std::endl;
}

// void	ScalarConverter::isInt(std::string const& input)
// {

// }


void	ScalarConverter::isFloat(std::string const& input)
{
	_float =  static_cast<float>(std::atof(input.c_str()));
	_int = static_cast<int>(_float);
	_char = static_cast<char>(_float);
	_double = static_cast<char>(_float);
}


void	ScalarConverter::isChar(std::string const& input)
{
	_char = input[0];
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}


// void	ScalarConverter::isDouble(std::string const& input)
// {

// }


/*
INPUT :
Figure out what was sent as input

1. Char : one character that is printable
2. Int : one or several numbers
3. Float : one or several numbers followed by .0f
4. Double : one or several numbers follewed by .0

Impossible numbers : array of strings to check

*/

// if (input.size() == 1 && std::isprint(input[0])) // It's a printable char sent as a char and nothing else
// 	{
// 		_char = input[0];
// 		std::cout << "char: " << _char << std::endl;
// 		std::cout << "int: " << static_cast<int>(_char) << std::endl;
// 		std::cout << "float: " << static_cast<float>(_char) << ".0f" << std::endl;
// 		std::cout << "double: " << static_cast<double>(_char) << ".0" << std::endl;
// 		return ;
// 	}
