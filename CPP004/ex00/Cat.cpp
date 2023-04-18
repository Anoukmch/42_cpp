/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:56:38 by amechain          #+#    #+#             */
/*   Updated: 2023/03/21 13:58:27 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat() : Animal() {
	_type = "Cat";
	std::cout << "Cat Default constructor called." << std::endl;
}

Cat::Cat( Cat const & src) : Animal(src) {
	std::cout << "Cat Copy constructed called" << std::endl;
	*this = src;
}

// Destructors
Cat::~Cat( void ) {
	std::cout << "Cat Destructor called." << std::endl;
}

// Operator overload
Cat & Cat::operator=( Cat const & src) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		_type = src.getType();
	}
	return ( *this );
}

// Member functions
void Cat::makeSound() const {
	std::cout << _type << " : Miaou Miaou" << std::endl;
}
