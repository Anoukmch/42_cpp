/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:56:38 by amechain          #+#    #+#             */
/*   Updated: 2023/03/23 17:56:46 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Constructors
AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << "Animal Default constructor called." << std::endl;
}

AAnimal::AAnimal( Animal const & src) {
	std::cout << "AAnimal Copy constructed called" << std::endl;
	*this = src;
}

// Destructors
AAnimal::~AAnimal( void ) {
	std::cout << "AAnimal Destructor called." << std::endl;
} // check which destructors is called when deleting a dog or a cat

// Operator overload
AAnimal & AAnimal::operator=( AAnimal const & src) {
	std::cout << "AAnimal Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		_type = src._type;
	}
	return ( *this );
}

// Member functions
void AAnimal::makeSound() const {
	std::cout << _type << " : Undescriptible aanimal sound" << std::endl;
}

std::string const &AAnimal::getType(void) const {
	return (_type);
}
