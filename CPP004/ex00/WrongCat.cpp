/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:56:38 by amechain          #+#    #+#             */
/*   Updated: 2023/03/21 13:58:27 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";
	std::cout << "WrongCat Default constructor called." << std::endl;
}

WrongCat::WrongCat( WrongCat const & src) : WrongAnimal(src) {
	std::cout << "WrongCat Copy constructed called" << std::endl;
	*this = src;
}

// Destructors
WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat Destructor called." << std::endl;
}

// Operator overload
WrongCat & WrongCat::operator=( WrongCat const & src) {
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		_type = src.getType();
	}
	return ( *this );
}

// Member functions
void WrongCat::makeSound() const {
	std::cout << _type << " : wrong Miaou Miaou" << std::endl;
}
