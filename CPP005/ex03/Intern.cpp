/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:11:35 by amechain          #+#    #+#             */
/*   Updated: 2023/06/05 19:20:49 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Constructors
Intern::Intern() {
	std::cout << "Intern Default constructor called." << std::endl;
}

Intern::Intern( Intern const & src) {
	std::cout << "Intern Copy constructed called" << std::endl;
	*this = src;
}

// Destructors
Intern::~Intern( void ) {
	std::cout << "Intern Destructor called." << std::endl;
}

// Operator overload
Intern & Intern::operator=( Intern const & src) {
	std::cout << "Intern Copy assignment operator called" << std::endl;
	if ( this != &src ) { ;}
	return ( *this );
}

// Members function
AForm* Intern::makeForm( std::string const& _formName, std::string const& _formTarget ) const {
	std::string arrayString[3] = { "robotomy request", "presidential pardon", "shrubbery creation" };
	std::cout << "-- Array for conditionnal test is being created --" << std::endl;
	AForm* arrayPointer[4] = { new RobotomyRequestForm(_formTarget), new PresidentialPardonForm(_formTarget), new ShrubberyCreationForm(_formTarget), NULL };
	std::cout << std::endl;
	for (int i = 0 ; i < 3 ; i++)
	{
		if (arrayString[i] == _formName) {
			std::cout << " > Intern has created " << arrayPointer[i]->getName() << std::endl << std::endl;
			std::cout << "-- Deleting unnecessary pointers --" << std::endl;
			for (int j = (i + 1) ; j < 4 ; j++)
				delete arrayPointer[j];
			return (arrayPointer[i]);
		}
		else
			delete(arrayPointer[i]);
	}
	throw FormDontExists();
}

const char* Intern::FormDontExists::what() const throw()
{
	return ("-> The form doesn't exists");
}


