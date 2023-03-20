/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:38:01 by mcombeau          #+#    #+#             */
/*   Updated: 2023/03/18 18:10:58 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

#define RESET "\e[0m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

/*	Default Constructor	*/
Fixed::Fixed( void ) : _fixPt( 0 )
{
	std::cerr << CYAN "Default constructor called." RESET << std::endl;
	return ;
}

/*	Copy Constructor	*/
Fixed::Fixed( Fixed const & src )
{
	std::cerr << CYAN "Copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

/*	Constructor from integer	*/
Fixed::Fixed( int const n ) : _fixPt( n << _fracBits )
{
	std::cerr << CYAN "Int constructor called." RESET << std::endl;
	return ;
}

/*	Constructor from float		*/
Fixed::Fixed( float const f ) : _fixPt( roundf(f * (1 << _fracBits)) )
{
	std::cerr << CYAN "Float constructor called." RESET << std::endl;
	return ;
}

/*	Desctructor	*/
Fixed::~Fixed( void )
{
	std::cerr << CYAN "Destructor called." RESET << std::endl;
	return ;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/
Fixed &	Fixed::operator=( Fixed const & src )
{
	std::cerr << YELLOW "Copy assignment operator called." RESET << std::endl;
	if ( this != &src )
		this->_fixPt = src.getRawBits();
	return ( *this );
}
// tester *this != src (dans le if) && this = src (dans le corps du if)
// pq on peut utiliser != alors qu'il est pas implement ?
// tester this->rax != src.getrawbits (ça ne doit pas marche sans l'opértor implement)

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/
int	Fixed::getRawBits( void ) const
{
	std::cerr << GREEN "getRawBits member function called." RESET << std::endl;
	return ( this->_fixPt );
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/
void	Fixed::setRawBits( int const raw )
{
	std::cerr << GREEN "setRawBits member funtion called." RESET << std::endl;
	this->_fixPt = raw;
	return ;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/
int		Fixed::toInt( void ) const
{
	return ( this->_fixPt >> Fixed::_fracBits );	
}

float	Fixed::toFloat( void ) const
{
	return ( (float)this->_fixPt / (1 << _fracBits) );
}

std::ostream& operator<<( std::ostream& os, const Fixed& number )
{
	os << number.toFloat();
	return ( os );
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
