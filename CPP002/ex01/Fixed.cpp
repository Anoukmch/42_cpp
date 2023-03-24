#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void) : _fixPt(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int integer) : _fixPt(integer << _fracBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fPoint) : _fixPt(roundf(fPoint * (1 << _fracBits))) {
	std::cout << "Float constructor called" << std::endl;
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

float Fixed::toFloat( void ) const {
	return ( (float)_fixPt / (1 << _fracBits));
}

int Fixed::toInt( void ) const {
	return ( _fixPt >> _fracBits);
}

// Operator overload
Fixed& Fixed::operator=(const Fixed & var) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &var)
		_fixPt = var.getRawBits();
	return (*this);
}

std::ostream &operator<<( std::ostream &flux, Fixed const& var) {
	flux << var.toFloat();
	return ( flux );
}

// in operator=, why not -> *this = var ? 
