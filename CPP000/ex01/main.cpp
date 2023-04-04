/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:25:04 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/03 18:25:05 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main()
{
	Phonebook pBook;
	std::string input;
	
	std::cout << "\nWelcome to The Awesome Crappy Phonebook\n\n";
	while (true)
	{
		std::cout << "-        MAIN MENU       -" << std::endl;
		std::cout << "  What can I do for you ?  \n\n";
		std::cout << "  > ADD" << std::endl;
		std::cout << "  > SEARCH" << std::endl;
		std::cout << "  > EXIT\n\n";

		input = pBook.getInput("> ", -1);
		if (input == "ADD")
			pBook.add();
		else if (input == "SEARCH")
			pBook.search();
		else if (input == "EXIT") {
			std::cout << "Goodbye" << std::endl;
			return (1); 
		}
		else {
			std::cout << "Please enter a valid command " << std::endl << std::endl;
		}
	}
	return (0);
}