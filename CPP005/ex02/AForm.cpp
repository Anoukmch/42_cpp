/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:21:56 by amechain          #+#    #+#             */
/*   Updated: 2023/04/11 17:00:24 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructors
AForm::AForm() : _name("Default name"), _isSigned(false), _gradeSign(LOWEST_GRADE), _gradeExe(LOWEST_GRADE) {
	std::cout << "AForm Default constructor called." << std::endl;
}

AForm::AForm( AForm const & src) : _name(src._name), _isSigned(false), _gradeSign(src._gradeSign), _gradeExe(src._gradeExe) {
	std::cout << "AForm Copy constructed called" << std::endl;
	std::cout << "AForm "<< _name << " has been created" << std::endl;
}

AForm::AForm( const std::string name, const int gradeSign, const int gradeExe) : _name(name),
																				_isSigned(false),
																				_gradeSign(gradeSign),
																				_gradeExe(gradeExe) {
	std::cout << "AForm overloaded constructor called." << std::endl;
	if (gradeSign < HIGHEST_GRADE || gradeExe < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (gradeSign > LOWEST_GRADE || gradeExe > LOWEST_GRADE)
		throw GradeTooLowException();
}

// Destructors
AForm::~AForm( void ) {
}

// Operator overload
AForm & AForm::operator=( AForm const & src) {
	std::cout << "AForm Copy assignment operator called" << std::endl;
	if ( this != &src )
		this->_isSigned = src.getIsSigned();
	return ( *this );
}

std::ostream &operator<<( std::ostream &flux, AForm const& var) {
		flux << "AForm name : " << var.getName()
	<< (var.getIsSigned() ? ". Document is signed" : ". Document is not signed. ")
	<< "It requires the grade " << var.getGradeSign() << " to be signed, and the grade " << var.getGradeExe()
	<< " to be executed";
	return ( flux );
}

// Getters
std::string const& AForm::getName(void) const { return this->_name; }

bool const& AForm::getIsSigned(void) const { return this->_isSigned; }

int const& AForm::getGradeSign(void) const { return this->_gradeSign; }

int const& AForm::getGradeExe(void) const { return this->_gradeExe; }

// Member functions
void	AForm::beSigned(Bureaucrat const& obj) {
	if (obj.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	else if (this->_isSigned == true )
		throw AlreadySigned();
	this->_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
	std::cout << "test : " << _gradeExe << std::endl;
	std::cout << "test : " << _gradeSign << std::endl;
	if (executor.getGrade() > _gradeExe)
		throw GradeTooLowException();
	else if (this->_isSigned == false )
		throw NotSigned();
	std::cout << executor.getName() << " executed " << this->_name << std::endl;
	this->ExecuteForm();
}

const char* AForm::AlreadySigned::what() const throw()
{
	return ("-> Document is already signed");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("-> Wrong grade input : too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("-> Wrong grade input : too low");
}

const char* AForm::NotSigned::what() const throw()
{
	return ("-> Document is not signed");
}
