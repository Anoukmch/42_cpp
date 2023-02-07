#include "Phonebook.hpp"

// Protect getline !
// Check color in Weapon attack (how to do bold ?)

// Constructors
Phonebook::Phonebook() { }

// Destructor
Phonebook::~Phonebook() { }

void Phonebook::GetInput(std::string str) {
	std::string input;

	while (!input)
	{
		std::cout << "Please enter: " << string << std::endl;
		std::getline (std::cin,input);
	}
	return (input);	
}

void Phonebook::IncrementIndex() {
	_index++;
	if (_index > 7)
		_index = 0;
}

void Phonebook::Add(void) {
	std::string input;

	IncrementIndex();
	std::cout << "-       ADD MENU :       -" << std::endl;
	std::cout << "-     Please fill in     -" << std::endl;
	input = GetInput("1. First name: ");
	_directory[_index].setFname(input);
	input = GetInput("2. Last name: ");
	_directory[_index].setLname(input);
	input = GetInput("3. Nickname: ");
	_directory[_index].setNname(input);
	input = GetInput("4. Phone number: ");
	_directory[_index].setNbr(input);
	input = GetInput("5. Darkest secret: ");
	_directory[_index].setSecret(input);
	std::cout << "Contact successfully saved" << std::endl;

}

void Phonebook::displayTable(void) {
	std::cout << "+----------+----------+----------+----------+" << std::endl
	<< "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
	<< "+----------+----------+----------+----------+" << std::endl;

	for (i = 0 ; i < 8 ; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
	}
}

void Phonebook::Search(void) { 

	std::cout << "-       SEARCH MENU :       -" << std::endl;
	if (_index == -1) {
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	displayTable();
}
