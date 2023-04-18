/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:10:58 by amechain          #+#    #+#             */
/*   Updated: 2023/04/07 14:04:34 by amechain         ###   ########.fr       */
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
		for (int i = 0 ; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	}
	return ( *this );
}

// Setter
void Brain::setIdea(int index, std::string const& idea) {
	ideas[index] = idea;
}

// Getter
std::string const& Brain::getIdea(int index) const {
	return (ideas[index]);
}

