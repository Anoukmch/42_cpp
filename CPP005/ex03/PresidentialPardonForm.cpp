/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:24:35 by amechain          #+#    #+#             */
/*   Updated: 2023/06/08 16:06:43 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("Default target") {
	std::cout << "PresidentialPardonForm Default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src) : AForm(src) {
	std::cout << "PresidentialPardonForm Copy constructed called" << std::endl;
	*this = src;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm overloaded constructor called." << std::endl;
}

// Destructors
PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << "PresidentialPardonForm Destructor called." << std::endl;
}

// Operator overload
PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & src) {
	std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	if ( this != &src )
		this->_target = src.getTarget();
	return ( *this );
}

// Getters
std::string const& PresidentialPardonForm::getTarget(void) const { return this->_target; }

// Members Function
void	PresidentialPardonForm::ExecuteForm( void ) const {
	std::cout << "Target " << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
