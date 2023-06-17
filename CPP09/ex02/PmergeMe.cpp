/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:00:11 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/15 22:11:22 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ALREADY SORTED DATA

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(int ac, char** ag)
{
	unsigned int nbr;
	// no duplicates (on vector)
	for (int i = 1; i < ac; ++i) // Try to send "" or " " or "digit digit"
	{
		nbr = isValidExpression(ag[i]);
		_vector.push_back(nbr);	
	}
	printer();
}

PmergeMe::PmergeMe( PmergeMe const & src) {
	*this = src;
}

// Destructors
PmergeMe::~PmergeMe( void ) {
}

// Operator overload
PmergeMe & PmergeMe::operator=( PmergeMe const & src) { // COMPLETE THAT and in all the cpp projects
	if ( this != &src ) {
		_vector = src._vector;
	}
	return ( *this );
}

unsigned int PmergeMe::isValidExpression(std::string const & number)
{
	std::istringstream iss(number); // if time, handle "2 3 4" (multiple digits in one argc & only one arg but with multiple digit
	float nbr; // try to send an incorrect data format : is !iss necessary ?

	for (std::string::const_iterator it = number.begin(); it != number.end(); ++it)
	{
        if (!isdigit(*it))
            throw std::logic_error("Wrong input format");
	}

	iss >> nbr; // would atol work here in case of "2p" input for ex ?

	if (nbr < 0 || iss.fail() || nbr > INT_MAX) // is iss.fail() enough ?
		throw std::logic_error("Wrong input format");
	return (nbr);
}

// Clarify this : if (value < 0 || !(iss && iss.eof())) throw std::runtime_error("Error");

void PmergeMe::printer(void)
{
	for (std::vector<unsigned int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << std::endl;
}