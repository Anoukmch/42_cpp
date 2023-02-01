#include "Phonebook.hpp"

int	main()
{
	std::cout << "Welcome to The Awesome Crappy Phonebook" << std::endl;
	while (true)
	{
		PhoneBook pBook;
		std::string input;

		std::cout << "- What can I do for you ? -" << std::endl;
		std::cout << ". ADD" << std::endl;
		std::cout << ". SEARCH" << std::endl;
		std::cout << ". EXIT" << std::endl;

		std::cout << "> ";
		std::getline (std::cin,input);
		std::cout << input << std::endl;
		if (input == "ADD")
			pBook.add();
		else if (input == "SEARCH")
			pBook.search();
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
}