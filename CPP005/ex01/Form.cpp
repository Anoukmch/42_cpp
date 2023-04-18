/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:21:56 by amechain          #+#    #+#             */
/*   Updated: 2023/04/11 17:00:24 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form() : _name("Default name"), _isSigned(false), _gradeSign(LOWEST_GRADE), _gradeExe(LOWEST_GRADE) {
	std::cout << "Form Default constructor called." << std::endl;
}

Form::Form( Form const & src) : _name(src._name), _isSigned(false), _gradeSign(src._gradeSign), _gradeExe(src._gradeExe) {
	std::cout << "Form Copy constructed called" << std::endl;
	std::cout << "Form "<< _name << " has been created" << std::endl;
}

Form::Form( const std::string name, const int gradeSign, const int gradeExe) : _name(name),
																				_isSigned(false),
																				_gradeSign(gradeSign), // TRY SENDING AN OUT OF RANGE INTEGER. IF BUG THEN CHANGE
																				_gradeExe(gradeExe) { // PAS FINI
	std::cout << "Form overloaded constructor called." << std::endl;
	if (gradeSign < HIGHEST_GRADE || gradeExe < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (gradeSign > LOWEST_GRADE || gradeExe > LOWEST_GRADE)
		throw GradeTooLowException();
	std::cout << "Form "<< _name << " has been created" << std::endl;
}

// Destructors
Form::~Form( void ) {
	std::cout << "Form Destructor called." << std::endl;
}

// Operator overload
Form & Form::operator=( Form const & src) {
	std::cout << "Form Copy assignment operator called" << std::endl;
	if ( this != &src )
		this->_isSigned = src.getIsSigned();
	return ( *this );
}

std::ostream &operator<<( std::ostream &flux, Form const& var) {
		flux << "Form name : " << var.getName()
	<< (var.getIsSigned() ? ". Document is signed" : ". Document is not signed. ")
	<< "It requires the grade " << var.getGradeSign() << " to be signed, and the grade " << var.getGradeExe()
	<< " to be executed";
	return ( flux );
}

// Getters
std::string const& Form::getName(void) const { return this->_name; }

bool const& Form::getIsSigned(void) const { return this->_isSigned; }

int const& Form::getGradeSign(void) const { return this->_gradeSign; }

int const& Form::getGradeExe(void) const { return this->_gradeExe; }

// Member functions

void	Form::beSigned(Bureaucrat const& obj) {
	if (obj.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	else if (this->_isSigned == true )
		throw AlreadySigned();
	this->_isSigned = true;
}

const char* Form::AlreadySigned::what() const throw()
{
	return ("-> Document is already signed");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("-> Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("-> Grade is too low");
}
