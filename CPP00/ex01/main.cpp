#include "Phonebook.hpp"

int	main()
{
	std::cout << "Welcome to The Awesome Crappy Phonebook" << std::endl;
	while (true)
	{
		Phonebook pBook;
		std::string input;

		std::cout << "-       MAIN MENU :       -" << std::endl;
		std::cout << "- What can I do for you ? -" << std::endl;
		std::cout << ". ADD" << std::endl;
		std::cout << ". SEARCH" << std::endl;
		std::cout << ". EXIT" << std::endl;

		std::cout << "> ";
		std::getline (std::cin,input);
		std::cout << input << std::endl;
		if (input == "ADD")
			pBook.Add();
		else if (input == "SEARCH")
			pBook.Search();
		else if (input == "EXIT")
			break ; 
		else 
		{
			std::cout << "- Please enter a valid command: -" << std::endl << std::endl;
			std::cout << "- . ADD                    -" << std::endl;
			std::cout << "- . SEARCH                 -" << std::endl;
			std::cout << "- . EXIT                   -" << std::endl;
		}
	}
	return (0);
}

// try to use reference constant whenever it is possible
// Check how to use an operator to avoir using a getters (in weapon exercise)