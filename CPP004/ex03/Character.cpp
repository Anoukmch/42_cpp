/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:25:03 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/03 18:01:45 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors
Character::Character() {
	std::cout << "Character Default constructor called." << std::endl;
}

Character::Character( Character const & src) {
	std::cout << "Character Copy constructed called" << std::endl;
	*this = src;
}

// Destructors
Character::~Character( void ) {
	std::cout << "Character Destructor called." << std::endl;
}

// Operator overload
Character & Character::operator=( Character const & src) {
	std::cout << "Character Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		
	}
	return ( *this );
}

// Member function 
