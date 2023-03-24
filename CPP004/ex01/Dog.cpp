/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:56:38 by amechain          #+#    #+#             */
/*   Updated: 2023/03/21 13:58:27 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog() : Animal(), _brain(new Brain()) {
	std::cout << "Dog Default constructor called." << std::endl;
	_type = "Dog";
}

Dog::Dog( Dog const & src) : Animal(), _brain(new Brain(*src._brain)) {
	std::cout << "Dog Copy constructed called" << std::endl;
	*this = src;
}

// Destructors
Dog::~Dog( void ) {
	std::cout << "Dog Destructor called." << std::endl;
	delete _brain;
}

// Operator overload
Dog & Dog::operator=( Dog const & src) {
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		_type = src._type;
	}
	return ( *this );
}

// Member functions
void Dog::makeSound() const {
	std::cout << _type << " : Wouf Wouf" << std::endl;
}
