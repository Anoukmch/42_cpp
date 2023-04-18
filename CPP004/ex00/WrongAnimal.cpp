/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:56:38 by amechain          #+#    #+#             */
/*   Updated: 2023/03/21 15:30:57 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src) {
	std::cout << "WrongAnimal Copy constructed called" << std::endl;
	*this = src;
}

// Destructors
WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal Destructor called." << std::endl;
}

// Operator overload
WrongAnimal & WrongAnimal::operator=( WrongAnimal const & src) {
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		_type = src.getType();
	}
	return ( *this );
}

// Member functions
void WrongAnimal::makeSound() const {
	std::cout << _type << " : Undescriptible wrong animal sound" << std::endl;
}

std::string const &WrongAnimal::getType(void) const {
	return (_type);
}
