#include "Phonebook.hpp"

// Protect getline !
// Check color in Weapon attack (how to do bold ?)

// Constructors
Phonebook::Phonebook() { }

// Destructor
Phonebook::~Phonebook() { }

void Phonebook::GetInput(std::string) {

}

void Phonebook::IncrementIndex() {
	_index++;
	if (_index > 7)
		_index = 0;
}

void Phonebook::Add(void) {
	std::string input;

	IncrementIndex();

	input = GetInput("1. First name: ");
	


	std::cout << "1. First name: ";
	std::getline (std::cin,input);
	std::cout << "2. Last name: ";
	std::getline (std::cin,input);
	std::cout << "3. Nickname: ";
	std::getline (std::cin,input);
	std::cout << "4. Phone number: ";
	std::getline (std::cin,input);
	std::cout << "5. Darkest secret: ";
	std::getline (std::cin,input);


}

/* Objectif : add a contact to the directory

Keep count on contact's index so we know if we have more than 8
Fill in everything for one contact (asking the cin)
*/

void Phonebook::search(void) { }
