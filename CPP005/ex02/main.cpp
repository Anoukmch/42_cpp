/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:24:14 by amechain          #+#    #+#             */
/*   Updated: 2023/06/18 20:23:46 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		PresidentialPardonForm PresidentialPardonForm("Lincoln Burrows");
		RobotomyRequestForm RobotomyRequestForm("Donald Trump");
		ShrubberyCreationForm ShrubberyCreationForm("Forest");
		std::cout << std::endl;
		//{
			Bureaucrat Winner("Winner", 1);
			Winner.signForm(PresidentialPardonForm);
		 	Winner.executeForm(PresidentialPardonForm);
			Winner.signForm(RobotomyRequestForm);
			Winner.executeForm(RobotomyRequestForm);
			Winner.signForm(ShrubberyCreationForm);
			Winner.executeForm(ShrubberyCreationForm);
		// }
		// std::cout << std::endl;
		// {
		// 	Bureaucrat Beginner("Beginner", 150);
		// 	Beginner.signForm(PresidentialPardonForm);
		// 	Beginner.executeForm(PresidentialPardonForm);
		// 	Beginner.signForm(RobotomyRequestForm);
		// 	Beginner.executeForm(RobotomyRequestForm);
		// 	Beginner.signForm(ShrubberyCreationForm);
		// 	Beginner.executeForm(ShrubberyCreationForm);
		// }
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
