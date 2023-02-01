#include "Phonebook.hpp"

// Protect getline !
// Check color in Weapon attack (how to do bold ?)

// Constructors 
PhoneBook::PhoneBook() { }

// Destructor 
PhoneBook::~PhoneBook() { }

void PhoneBook::add(void) { 
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

// Recupérer l'index du contact


void PhoneBook::search(void) { }