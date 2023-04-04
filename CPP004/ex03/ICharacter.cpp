/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:25:03 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/03 16:07:18 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

// Constructors
ICharacter::ICharacter() {
	std::cout << "ICharacter Default constructor called." << std::endl;
}

ICharacter::ICharacter( ICharacter const & src) {
	std::cout << "ICharacter Copy constructed called" << std::endl;
	*this = src;
}

// Destructors
ICharacter::~ICharacter( void ) {
	std::cout << "ICharacter Destructor called." << std::endl;
}

// Operator overload
ICharacter & ICharacter::operator=( ICharacter const & src) {
	std::cout << "ICharacter Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		
	}
	return ( *this );
}

// Member function 
