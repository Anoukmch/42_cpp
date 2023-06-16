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
	// Only digit separated by amount of space
	// int ranges (on atol) + no negative numbers
	// no duplicates (on vector)

	for (size_t i = 0; i < ac; ++i)
		isValidExpression(ag[i]);
}

PmergeMe::PmergeMe( PmergeMe const & src) {
	*this = src;
}

// Destructors
PmergeMe::~PmergeMe( void ) {
}

// Operator overload
PmergeMe & PmergeMe::operator=( PmergeMe const & src) {
	if ( this != &src ) {
		// Do something
	}
	return ( *this );
}

void PmergeMe::isValidExpression(std::string const & number)
{
	std::istringstream iss(number);
	float nbr;

	iss >> nbr;
	std::cout << nbr << std::endl;
}

// Clarify this : if (value < 0 || !(iss && iss.eof())) throw std::runtime_error("Error");
