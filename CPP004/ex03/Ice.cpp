/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:16:31 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/03 15:57:02 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors
Ice::Ice() : AMateria("ice") {
	std::cout << "Animal Default constructor called." << std::endl;
}

Ice::Ice( Ice const & src) : AMateria("ice") {
	std::cout << "Ice Copy constructed called" << std::endl;
	*this = src;
}

// Destructors
Ice::~Ice( void ) {
	std::cout << "Ice Destructor called." << std::endl;
}

// Operator overload
Ice & Ice::operator=( Ice const & src) {
	std::cout << "Ice Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		_type = src._type; // REMOVE ? 
	}
	return ( *this );
}

// Member function 
AMateria* Ice::clone() const { // should I return AMateria or Cure ? 
	return (new Ice());
}