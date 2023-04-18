/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:11:35 by amechain          #+#    #+#             */
/*   Updated: 2023/04/12 18:32:11 by amechain         ###   ########.fr       */
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
	return ( *this );
}

// Members function
AForm* Intern::makeForm( std::string const& _formName, std::string const& _formTarget ) const {
	std::string arrayString[3] = { "robotomy request", "presidential pardon", "shrubbery creation" };
	AForm* arrayPointer[4] = { new RobotomyRequestForm(_formTarget), new PresidentialPardonForm(_formTarget), new ShrubberyCreationForm(_formTarget), NULL };
	for (int i = 0 ; i < 3 ; i++)
	{
		if (arrayString[i] == _formName) {
			std::cout << "Intern creates " << arrayPointer[i]->GetName() << std::endl;
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


