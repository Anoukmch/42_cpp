/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:16:28 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/07 21:02:37 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructors
Cure::Cure() : AMateria("cure") {
	std::cout << "Cure Default constructor called." << std::endl;
}

Cure::Cure( Cure const & src) : AMateria(src) {
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
		_type = src._type;
	}
	return ( *this );
}

// Member function
AMateria* Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << " 's wounds *" << std::endl;
}
