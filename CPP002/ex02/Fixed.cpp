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

// tester *this != src (dans le if) && this = src (dans le corps du if)
// pq on peut utiliser != alors qu'il est pas implement ?
// tester this->rax != src.getrawbits (ça ne doit pas marche sans l'opértor implement)
// in operator=, why not -> *this = var ?

std::ostream &operator<<( std::ostream &flux, Fixed const& var) {
	flux << var.toFloat();
	return ( flux );
}

// MY CODE

// COMPARISON OPERATORS
bool Fixed::operator==(Fixed const& a) {
	return (_fixPt == a.getRawBits());
}

bool Fixed::operator!=(Fixed const& a) {
	return (_fixPt != a.getRawBits());
}

bool Fixed::operator>(Fixed const &a) {
	return (_fixPt > a.getRawBits());
}

bool Fixed::operator<(Fixed const &a) {
	return (_fixPt < a.getRawBits());
}

bool Fixed::operator>=(Fixed const &a) {
	return (_fixPt >= a.getRawBits());
}

bool Fixed::operator<=(Fixed const &a) {
	return (_fixPt <= a.getRawBits());
}

// ARITHMETIC OPERATORS

Fixed Fixed::operator+(Fixed const& a) {
	return (this->toFloat() + a.toFloat());
}
Fixed Fixed::operator-(Fixed const& a) {
	return (this->toFloat() - a.toFloat());
}
Fixed Fixed::operator*(Fixed const& a) {
	return (this->toFloat() * a.toFloat());
}
Fixed Fixed::operator/(Fixed const& a) {
	return (this->toFloat() / a.toFloat());
}

// -CREMENT OPERATORS

Fixed& Fixed::operator++(void) {
	++_fixPt;
	return (*this);
}
// ou += 1 ?

Fixed Fixed::operator++(int) {
	Fixed buf(*this);

	operator++();
	// tester _fixPt++;
	return (buf);
}

Fixed& Fixed::operator--(void) {
	--_fixPt;
	return (*this);
}
Fixed Fixed::operator--(int) {
	Fixed buf(*this);

	operator--();
	// tester _fixPt--;
	return (buf);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed & Fixed::min(Fixed const& a, Fixed const& b) {
	if (a < b) // methode constante ">" et "<" 
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return (a);
	return (b);
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b) {
	if (a > b)
		return (a);
	return (b);
}


