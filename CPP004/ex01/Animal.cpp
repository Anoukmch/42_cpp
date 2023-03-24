/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:56:38 by amechain          #+#    #+#             */
/*   Updated: 2023/03/23 17:32:26 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors
Animal::Animal() : _type("Animal") {
	std::cout << "Animal Default constructor called." << std::endl;
}

Animal::Animal( Animal const & src) {
	std::cout << "Animal Copy constructed called" << std::endl;
	*this = src;
}

// Destructors
Animal::~Animal( void ) {
	std::cout << "Animal Destructor called." << std::endl;
} // check which destructors is called when deleting a dog or a cat

// Operator overload
Animal & Animal::operator=( Animal const & src) {
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		_type = src._type;
	}
	return ( *this );
}

// Member functions
void Animal::makeSound() const {
	std::cout << _type << " : Undescriptible animal sound" << std::endl;
}

std::string const &Animal::getType(void) const {
	return (_type);
}
