/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:16:31 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/07 21:02:43 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors
Ice::Ice() : AMateria("ice") {
	std::cout << "Ice Default constructor called." << std::endl;
}

Ice::Ice( Ice const & src) : AMateria(src) {
	std::cout << "Ice Copy constructed called" << std::endl;
	*this = src;
}

// Destructors
Ice::~Ice( void ) {
	std::cout << "Ice Destructor called." << std::endl;
}

// Operator overload
Ice & Ice::operator=( Ice const & src) {
	std::cout << "Ice Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		_type = src._type;
	}
	return ( *this );
}

// Member function
AMateria* Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
