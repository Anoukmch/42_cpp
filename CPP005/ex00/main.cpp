/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:33:43 by amechain          #+#    #+#             */
/*   Updated: 2023/04/11 16:14:17 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	createBureaucrat(std::string name, int grade)
{
	try
	{
		Bureaucrat bureaucrat(name, grade); // has bureaucrat been created ? Why the destructor isn't called ?
		Bureaucrat Bernard("Bernard", 5);
	}
	catch(std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	changeGrade(Bureaucrat &obj, std::string test)
{
	try
	{
		if (test == "++")
			obj.incrementGrade();
		else if (test == "-")
			obj.decrementGrade();
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main()
{

	Bureaucrat Henry;
	Bureaucrat Paul("Paul", 5);
	Bureaucrat Paulette(Paul);

	std::cout << "Henry's name : " << Henry.getName() << std::endl;
	std::cout << "Henry's grade : " << Henry.getGrade() << std::endl;
	std::cout << "Paulette's name : " << Paulette.getName() << std::endl;
	std::cout << "Paulette's grade : " << Paulette.getGrade() << std::endl;

	std::cout << std::endl;

	try
	{
		Bureaucrat Jacques("Jacques", -5);
		Bureaucrat Jacquette(Jacques);
		std::cout << "Should not be printed" << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	createBureaucrat("Pierre", 1);
	createBureaucrat("Pierrette", 150);
	createBureaucrat("Jacques", -3);
	createBureaucrat("Jacquette", 200);

	std::cout << std::endl;

	Bureaucrat Alfie("Alfie", 1);
	Bureaucrat Alfette("Alfette", 150);

	changeGrade(Alfie, "+");
	changeGrade(Alfie, "-");
	changeGrade(Alfette, "-");
	changeGrade(Alfette, "+");

	return (0);
}
