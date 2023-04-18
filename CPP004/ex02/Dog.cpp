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
Dog::Dog() : AAnimal(), _brain(new Brain()) {
	std::cout << "Dog Default constructor called." << std::endl;
	_type = "Dog";
}

Dog::Dog( Dog const & src) : AAnimal(src), _brain(NULL) {
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
		_type = src.getType();
		if (_brain != NULL)
			delete _brain;
		_brain = new Brain(*src._brain);
	}
	return ( *this );
}

// Member functions
void Dog::makeSound() const {
	std::cout << _type << " : Wouf Wouf" << std::endl;
}

// Setter
void Dog::setIdea(int i, std::string const& idea) { _brain->setIdea(i, idea); }

// Getter
std::string const& Dog::getIdea(int index) const { return(_brain->getIdea(index)); }
