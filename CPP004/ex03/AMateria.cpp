/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:16:24 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/03 15:56:44 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructors
AMateria::AMateria() : _type("AMateria") {
	std::cout << "Materia Default constructor called." << std::endl;
}

AMateria::AMateria( AMateria const & src) {
	std::cout << "AMateria Copy constructed called" << std::endl;
	*this = src;
}

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "AMateria overload constructed called" << std::endl;
}

// Destructors
AMateria::~AMateria( void ) {
	std::cout << "AMateria Destructor called." << std::endl;
}

// Operator overload
AMateria & AMateria::operator=( AMateria const & src) {
	std::cout << "AMateria Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		_type = src._type; // REMOVE ? 
	}
	return ( *this );
}

// Member function 
std::string const & AMateria::getType() const {
	return (_type);
}

void AMateria::use(ICharacter& target) {
	
}
