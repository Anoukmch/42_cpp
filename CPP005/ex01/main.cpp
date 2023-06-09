/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:33:43 by amechain          #+#    #+#             */
/*   Updated: 2023/06/08 18:03:13 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	createForm(std::string name, int gradeSign, int gradeExe)
{
	try
	{
		Form form(name, gradeSign, gradeExe);
	}
	catch(std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	main()
{
	Form Upgrade;
	Form Registration_test("Registration", 5, 15);
	Form Registration(Registration_test);

	std::cout << std::endl;

	createForm("Demission", -2, 3);
	createForm("Tax", 2, 160);
	createForm("Refund", 2, 10);
	createForm("Data", 100, 40);

	std::cout << std::endl;

	Form GDPR("GDPR", 2, 10);
	Bureaucrat Jeff("Jeff", 10);
	Bureaucrat Henrique("Henrique", 1);

	std::cout << std::endl;

	std::cout << Jeff << std::endl;
	std::cout << GDPR << std::endl;

	std::cout << std::endl;

	Jeff.signForm(GDPR);
	Henrique.signForm(GDPR);
	Henrique.signForm(GDPR);

	return (0);
}
