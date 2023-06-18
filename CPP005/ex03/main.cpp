/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:24:06 by amechain          #+#    #+#             */
/*   Updated: 2023/06/18 17:49:25 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat someRandomBureaucrat("someRandomBureaucrat", 1);

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << "\n-- Testing newly created form --" << std::endl;
		std::cout << *rrf << std::endl;
		rrf->beSigned(someRandomBureaucrat);
		rrf->execute(someRandomBureaucrat);
		someRandomBureaucrat.signForm(*rrf);
		someRandomBureaucrat.executeForm(*rrf);
	}
	catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
	std::cout << std::endl;
}
