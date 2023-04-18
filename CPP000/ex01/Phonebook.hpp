/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:24:51 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/04 17:16:39 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook();
		~Phonebook();
		void add();
		void search();
		void displayContact(void);
		void displayTable(void);
		void incrementIndex(void);
		std::string getInput(std::string const& str, int const& code);
		bool containsOnlyAlpha(std::string const& s);
		bool containsOnlyDigits(std::string const& s);
		bool notOnlySpace(std::string const& s);

    private:
       Contact _directory[8];
	   int		_index;
	   int		_count;
};

#endif
