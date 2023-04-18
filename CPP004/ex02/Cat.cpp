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
Cat::Cat() : AAnimal(), _brain(new Brain()) {
	std::cout << "Cat Default constructor called." << std::endl;
	_type = "Cat";
}

Cat::Cat( Cat const & src) : AAnimal(src), _brain(NULL) {
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = src;
}

// Destructors
Cat::~Cat( void ) {
	std::cout << "Cat Destructor called." << std::endl;
	delete _brain;
}

// Operator overload
Cat & Cat::operator=( Cat const & src) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		_type = src.getType();
		if (_brain != NULL)
			delete _brain;
		_brain = new Brain(*src._brain);
	}
	return ( *this );
}

// Member functions
void Cat::makeSound() const {
	std::cout << _type << " : Miaou Miaou" << std::endl;
}

// Setter
void Cat::setIdea(int i, std::string const& idea) { _brain->setIdea(i, idea); }

// Getter
std::string const& Cat::getIdea(int index) const { return(_brain->getIdea(index)); }

