/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:20:21 by amechain          #+#    #+#             */
/*   Updated: 2023/04/06 13:48:09 by amechain         ###   ########.fr       */
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

// Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

// Members Functions
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixPt);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixPt = raw;
}

// Operator overload
Fixed& Fixed::operator=(const Fixed & var) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &var)
		this->_fixPt = var.getRawBits();
	return (*this);
}

