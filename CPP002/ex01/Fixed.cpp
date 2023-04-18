/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:10:37 by amechain          #+#    #+#             */
/*   Updated: 2023/04/06 13:47:45 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (this->_fixPt);
}

void Fixed::setRawBits(int const raw) {
	this->_fixPt = raw;
}

float Fixed::toFloat( void ) const {
	return ( (float)this->_fixPt / (1 << this->_fracBits));
}

int Fixed::toInt( void ) const {
	return ( this->_fixPt >> this->_fracBits);
}

// Operator overload
Fixed& Fixed::operator=(const Fixed & var) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &var)
		this->_fixPt = var.getRawBits();
	return (*this);
}

std::ostream &operator<<( std::ostream &flux, Fixed const& var) {
	flux << var.toFloat();
	return ( flux );
}
