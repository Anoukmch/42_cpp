/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:10:43 by amechain          #+#    #+#             */
/*   Updated: 2023/04/06 14:04:40 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void) : _fixPt(0) {
}

Fixed::Fixed(Fixed const& copy) {
	*this = copy;
}

Fixed::Fixed(const int integer) : _fixPt(integer << _fracBits) {
}

Fixed::Fixed(const float fPoint) : _fixPt(roundf(fPoint * (1 << _fracBits))) {
}

// Destructor
Fixed::~Fixed(void) {
}

// Members Functions
int Fixed::getRawBits(void) const {
	return (this->_fixPt);
}

void Fixed::setRawBits(int const raw) {
	this->_fixPt = raw;
}

float Fixed::toFloat( void ) const {
	return ( (float)this->_fixPt / (1 << _fracBits));
}

int Fixed::toInt( void ) const {
	return ( this->_fixPt >> _fracBits);
}

// Operator overload
Fixed& Fixed::operator=(const Fixed & var) {
	if (this != &var)
		this->_fixPt = var.getRawBits();
	return (*this);
}

std::ostream &operator<<( std::ostream &flux, Fixed const& var) {
	flux << var.toFloat();
	return ( flux );
}

// COMPARISON OPERATORS
bool Fixed::operator==(Fixed const& a) const {
	return (this->_fixPt == a.getRawBits());
}

bool Fixed::operator!=(Fixed const& a) const {
	return (this->_fixPt != a.getRawBits());
}

bool Fixed::operator>(Fixed const &a) const {
	return (this->_fixPt > a.getRawBits());
}

bool Fixed::operator<(Fixed const& a) const {
	return (this->_fixPt < a.getRawBits());
}

bool Fixed::operator>=(Fixed const &a) const {
	return (this->_fixPt >= a.getRawBits());
}

bool Fixed::operator<=(Fixed const &a) const {
	return (this->_fixPt <= a.getRawBits());
}

// ARITHMETIC OPERATORS

Fixed Fixed::operator+(Fixed const& a) const {
	return (this->toFloat() + a.toFloat());
}

Fixed Fixed::operator-(Fixed const& a) const {
	return (this->toFloat() - a.toFloat());
}

Fixed Fixed::operator*(Fixed const& a) const {
	return (this->toFloat() * a.toFloat());
}

Fixed Fixed::operator/(Fixed const& a) const {
	return (this->toFloat() / a.toFloat());
}

// -CREMENT OPERATORS

Fixed& Fixed::operator++(void) {
	++this->_fixPt;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed buf(*this);

	++(*this);
	return (buf);
}

Fixed& Fixed::operator--(void) {
	--this->_fixPt;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed buf(*this);

	--(*this);
	return (buf);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed & Fixed::min(Fixed const& a, Fixed const& b) {
	if (a < b)
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
