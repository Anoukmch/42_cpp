/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:24:44 by amechain          #+#    #+#             */
/*   Updated: 2023/06/18 18:15:19 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("Default target") {
	std::cout << "ShrubberyCreationForm Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src) : AForm(src) {
	std::cout << "ShrubberyCreationForm Copy constructed called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm overloaded constructor called." << std::endl;
}

// Destructors
ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << "ShrubberyCreationForm Destructor called." << std::endl;
}

// Operator overload
ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & src) {
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	if ( this != &src )
		this->_target = src.getTarget();
	return ( *this );
}

// Getters
std::string const& ShrubberyCreationForm::getTarget(void) const { return this->_target; }

// Members Function
void	ShrubberyCreationForm::ExecuteForm( void ) const {
	std::ofstream outfile((_target + "_shrubbery").c_str(), std::ofstream::app);

	if(!outfile.is_open())
		throw std::logic_error("failed to open " + getName() + " file");

	outfile << "           *" << std::endl;
	outfile << "          /|\\" << std::endl;
	outfile << "         / | \\" << std::endl;
	outfile << "        /  |  \\" << std::endl;
	outfile << "       /   |   \\" << std::endl;
	outfile << "      /    |    \\" << std::endl;
	outfile << "     /     |     \\" << std::endl;
	outfile << "    /      |      \\" << std::endl;
	outfile << "   /       |       \\" << std::endl;
	outfile << "  /        |        \\" << std::endl;
	outfile << " /_________|_________\\" << std::endl;
	outfile << "     |     |     |" << std::endl;
	outfile << "     |     |     |" << std::endl;
	std::cout << "ASCII trees is now located at " << this->_target << std::endl;
	outfile.close();
}
