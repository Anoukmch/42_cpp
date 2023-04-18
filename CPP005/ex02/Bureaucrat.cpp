/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:48:55 by amechain          #+#    #+#             */
/*   Updated: 2023/04/12 17:10:09 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : _name("Default name"), _grade(LOWEST_GRADE) {
	std::cout << "Bureaucrat Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src) : _name(src._name) {
	std::cout << "Bureaucrat Copy constructed called" << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(LOWEST_GRADE) {
	std::cout << "Bureaucrat overloaded constructor called." << std::endl;
	std::cout << "Bureaucrat " << _name << " ";
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	this->_grade = grade;
	std::cout << "was created with grade " << this->_grade << std::endl;
}

// Destructors
Bureaucrat::~Bureaucrat( void ) {
	std::cout << "Bureaucrat Destructor called." << std::endl;
}

// Operator overload
Bureaucrat & Bureaucrat::operator=( Bureaucrat const & src) {
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	if ( this != &src )
		_grade = src.getGrade();
	return ( *this );
}

std::ostream &operator<<( std::ostream &flux, Bureaucrat const& var) {
	flux << var.getName() << ", bureaucrat grade " << var.getGrade() << ".";
	return ( flux );
}

// Getters
std::string const& Bureaucrat::getName(void) const {
	return (this->_name);
}

int const& Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

// Member functions
void	Bureaucrat::incrementGrade(void) {
	std::cout << "Bureaucrat " << this->_name << " ";
	if (this->_grade <= HIGHEST_GRADE)
		throw GradeTooHighException();
	this->_grade--;
	std::cout << "was promoted to grade " << this->_grade << std::endl;
}

void	Bureaucrat::decrementGrade(void) {
	std::cout << "Bureaucrat " << this->_name << " ";
	if (this->_grade >= LOWEST_GRADE)
		throw GradeTooLowException();
	this->_grade++;
	std::cout << "was relegated to grade " << this->_grade << std::endl;
}

void	Bureaucrat::signForm(AForm & obj) const {
	try
	{
		obj.beSigned(*this);
		std::cout << this->_name << " signed " << obj.getName() << std::endl;

	}
	catch(std::exception const& e)
	{
		std::cerr << this->_name << " couldn't sign " << obj.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) {
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("cannot be graded. The grade is out of range : above highest");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("cannot be graded. The grade is out of range : below lowest");
}
