/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:24:39 by amechain          #+#    #+#             */
/*   Updated: 2023/06/18 17:20:25 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


// Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("Default target") {
	std::cout << "RobotomyRequestForm Default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src) {
	std::cout << "RobotomyRequestForm Copy constructed called" << std::endl;
	*this = src;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) : AForm("Robotomy Request Form", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm overloaded constructor called." << std::endl;
}

// Destructors
RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << "RobotomyRequestForm Destructor called." << std::endl;
}

// Operator overload
RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & src) {
	std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	if ( this != &src )
		this->_target = src.getTarget();
	return ( *this );
}

// Getters
std::string const& RobotomyRequestForm::getTarget(void) const { return this->_target; }

// Members Function
void	RobotomyRequestForm::ExecuteForm( void ) const {
	std::cout << "Brzzzzzzzzzzzzzzzzzzzzzzz! ";
	std::srand(time(0));

	if (std::rand() % 2)
		std::cout << "Target " << this->_target << " has been robotomized !" << std::endl;
	else
		std::cout << "Target " << this->_target << " resisted robotomization !" << std::endl;
}
