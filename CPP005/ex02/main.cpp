/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:24:14 by amechain          #+#    #+#             */
/*   Updated: 2023/04/12 17:00:56 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat Pierre("Pierre", 1);
	std::cout << std::endl;
	Bureaucrat Paul("Paul", 50);
	std::cout << std::endl;
	Bureaucrat Jacques("Jacques", 1);

	std::cout << std::endl;
	PresidentialPardonForm PresidentialPardonForm(Pierre.getName());
	std::cout << std::endl;
	RobotomyRequestForm RobotomyRequestForm("Donald Trump");
	std::cout << std::endl;
	ShrubberyCreationForm ShrubberyCreationForm("Forest");

	std::cout << std::endl;
	Pierre.signForm(RobotomyRequestForm);
	std::cout << std::endl;
	Pierre.executeForm(RobotomyRequestForm);
	std::cout << std::endl;
	Jacques.executeForm(RobotomyRequestForm);
	std::cout << std::endl;
	Jacques.executeForm(RobotomyRequestForm);
	std::cout << std::endl;
}
