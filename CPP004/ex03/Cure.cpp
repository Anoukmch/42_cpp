/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:16:28 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/03 15:56:58 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructors
Cure::Cure() : AMateria("cure") {
	std::cout << "Animal Default constructor called." << std::endl;
}

Cure::Cure( Cure const & src) : AMateria("cure") {
	std::cout << "Cure Copy constructed called" << std::endl;
	*this = src;
}

// Destructors
Cure::~Cure( void ) {
	std::cout << "Cure Destructor called." << std::endl;
}

// Operator overload
Cure & Cure::operator=( Cure const & src) {
	std::cout << "Cure Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		_type = src._type; // REMOVE ? 
	}
	return ( *this );
}

// Member function 
AMateria* Cure::clone() const { // should I return AMateria or Cure ? 
	return (new Cure());
}