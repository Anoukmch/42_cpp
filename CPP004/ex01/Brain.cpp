/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:10:58 by amechain          #+#    #+#             */
/*   Updated: 2023/03/23 17:32:21 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
Brain::Brain() {
	std::cout << "Brain Default constructor called." << std::endl;
}

Brain::Brain( Brain const & src) {
	std::cout << "Brain Copy constructed called" << std::endl;
	*this = src;
}

// Destructors
Brain::~Brain( void ) {
	std::cout << "Brain Destructor called." << std::endl;
}

// Operator overload
Brain & Brain::operator=( Brain const & src) {
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		// FILL IT
	}
	return ( *this );
}
