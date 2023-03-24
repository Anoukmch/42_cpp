#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void) : _fixPt(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

// Members Functions
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixPt);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixPt = raw;
}

// Operator overload
Fixed& Fixed::operator=(const Fixed & var) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &var)
		_fixPt = var.getRawBits();
	return (*this);
}

// in operator=, why not -> *this = var ?
