#include "Phonebook.hpp"

// Protect getline !
// Check color in Weapon attack (how to do bold ?)

// Constructors
Phonebook::Phonebook() { }

// Destructor
Phonebook::~Phonebook() { }

void Phonebook::getInput(std::string str) {
	std::string input;

	while (!input)
	{
		std::cout << "Please enter: " << string << std::endl;
		std::getline (std::cin,input);
	}
	return (input);	
}

void Phonebook::incrementIndex() {
	_index++;
	if (_index > 7)
		_index = 0;
}

void Phonebook::add(void) {
	std::string input;

	incrementIndex();
	std::cout << "-       ADD MENU :       -" << std::endl;
	std::cout << "-     Please fill in     -" << std::endl;
	input = getInput("1. First name: ");
	_directory[_index].setFname(input);
	input = getInput("2. Last name: ");
	_directory[_index].setLname(input);
	input = getInput("3. Nickname: ");
	_directory[_index].setNname(input);
	input = getInput("4. Phone number: ");
	_directory[_index].setNbr(input);
	input = getInput("5. Darkest secret: ");
	_directory[_index].setSecret(input);
	std::cout << "Contact successfully saved" << std::endl;

}

void Phonebook::displayTable(void) {
	std::cout << "+----------+----------+----------+----------+" << std::endl
	<< "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
	<< "+----------+----------+----------+----------+" << std::endl;

	for (i = 0 ; i < 8 ; i++) // if less than 8 contacts ? 
	{
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << "|" << std::setw(10) << _directory[_index].getFname() << "|";
		std::cout << "|" << std::setw(10) << _directory[_index].getLname() << "|";
		std::cout << "|" << std::setw(10) << _directory[_index].getNname() << "|";
	}
	std::cout << std::endl << "+----------+----------+----------+----------+" << std::endl;
}

void Phonebook::displayContact(void) {

}

void Phonebook::search(void) { 
	std::string input;

	std::cout << "-       SEARCH MENU :       -" << std::endl;
	if (_index == -1) {
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	displayTable();
	input = getInput("the contact's index to display");
	displayContact();
}
