#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include <string>

#include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook();
		~Phonebook();
		void Add();
		void Search();

    private:
       Contact _directory[8];
	   int		_index;
};

#endif
