#include "Phonebook.hpp"

// Constructors
Phonebook::Phonebook() : _index(-1), _count(0) { }

// Destructor
Phonebook::~Phonebook() { }

bool Phonebook::notOnlySpace(std::string const& s) {
    for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
        if (*it != ' ' && *it != '\t' && *it != '\n') { return (true); }
    }
    return (false);
}

bool Phonebook::containsOnlyAlpha(std::string const& s) {
    for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
        if (!isalpha(s[0]) && *it != '-') { return (false); } 
    }
    return (true);
}

bool Phonebook::containsOnlyDigits(std::string const& s) {
    for (std::string::const_iterator it = s.begin(); it != s.end(); it++) {
        if (!isdigit(*it)) { return (false); }
    }
    return (true);
}

std::string Phonebook::getInput(std::string const& str, int const& code) {
	std::string input;

	while (true) 
	{
		std::cout << str;
		if (!std::getline(std::cin,input) || std::cin.eof()) { // Ask for difference 
			std::cout << "Goodbye" << std::endl;
			exit(0);
		}
		if (input.empty())
			std::cout << "Please enter an input" << std::endl;
		else if ((code == 1 || code == 3) && !containsOnlyDigits(input))
			std::cout << "Your entry must contains only digits" << std::endl;
		else if (code == 2 && !notOnlySpace(input))
			std::cout << "Please enter a valid Dark Secret" << std::endl;
		else if (code == 0 && !containsOnlyAlpha(input))
			std::cout << "Your entry must contains only letters" << std::endl;
		else if (code == 3 && (atoi(input.c_str()) < 0 || atoi(input.c_str()) > _count)) {
				std::cout << "Please enter a valid index such as ";
				for (int i = 0 ; i <= _count ; i++)
					std::cout << i << "/";
				std::cout << std::endl;
		}
		else
			break ;
	}
	return (input);	
}

void Phonebook::incrementIndex() {
	_index++;
	if (_index > 7) {
		_index = 0;
		_count = 7;
	}
	else
		_count = _index;
}

void Phonebook::add(void) {
	std::string input;

	incrementIndex();
	std::cout << "\n-      ADD CONTACT      -" << std::endl;
	std::cout << "     Please fill in     \n\n";
	input = getInput("First name > ", 0);
	_directory[_index].setFname(input);
	input = getInput("Last name > ", 0);
	_directory[_index].setLname(input);
	input = getInput("Nickname > ", 0);
	_directory[_index].setNname(input);
	input = getInput("Phone number > ", 1);
	_directory[_index].setNbr(input);
	input = getInput("Darkest secret > ", 2);
	_directory[_index].setSecret(input);
	std::cout << "\nContact successfully saved\n\n";
}

void Phonebook::displayTable(void) {
	std::cout << "+----------+----------+----------+----------+" << std::endl
	<< "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
	<< "+----------+----------+----------+----------+" << std::endl;

	for (int i = 0 ; i <= _count ; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << _directory[i].getFname() << "|";
		std::cout << std::setw(10) << _directory[i].getLname() << "|";
		std::cout << std::setw(10) << _directory[i].getNname() << "|" << std::endl;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void Phonebook::displayContact(void) {
	std::string input;
	int index;

	input = getInput("Contact's index to display > ", 3);
	index = atoi(input.c_str());
	std::cout << "1. First name: " << _directory[index].getFname() << std::endl
				<< "2. Last name: " << _directory[index].getLname() << std::endl
				<< "3. Nickname: " << _directory[index].getNname() << std::endl
				<< "4. Phonenumber: " << _directory[index].getNbr() << std::endl
				<< "5. Darkest secret: " << _directory[index].getSecret() << std::endl;

}

void Phonebook::search(void) { 
	std::cout << "-       SEARCH CONTACT       -" << std::endl;
	if (_index == -1) {
		std::cout << "The Phonebook is empty\n" << std::endl;
		return ;
	}
	displayTable();
	displayContact();
}
