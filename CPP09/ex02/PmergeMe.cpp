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

// CHECK ALREADY SORTED INPUT

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(int ac, char** ag) : _odd(-1)
{
	unsigned int nbr;
	for (int i = 1; i < ac; ++i)
	{
		nbr = isValidExpression(ag[i]);

		if (std::find(_vector.begin(), _vector.end(), nbr) != _vector.end()) continue;

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
PmergeMe & PmergeMe::operator=( PmergeMe const & src) { // COMPLETE operator= and in all the cpp projects
	if ( this != &src ) {
		_vector = src._vector;
	}
	return ( *this );
}

unsigned int PmergeMe::isValidExpression(std::string const & number)
{
	std::istringstream iss(number);
	float nbr;

	iss >> nbr;
	if (nbr < 0 || iss.fail() || nbr > INT_MAX) // is !iss necessary ?
		throw std::logic_error("Wrong input format");
	if (!iss.eof())
	{
		iss >> std::ws;
		if (!iss.eof())
			throw std::logic_error("Wrong input format");
	}
	return (nbr);
}

void PmergeMe::printer(void)
{
	std::cout << "Before: ";
	for (std::vector<unsigned int>::iterator it = _vector.begin(); it != _vector.begin() + 4 ; ++it)
		std::cout << *it << " ";
	if (_vector.size() > 4) std::cout << "[...]";
	std::cout << std::endl;
}

void PmergeMe::sort(void)
{
	if (_vector.size() % 2 != 0)
	{
		_odd = _vector.back();
		_vector.pop_back();
	}

	std::vector< std::pair<unsigned int, unsigned int> > pairsVector;
	pairsVector = create_pairs(); // We can save one line of code ! Shouldnt pairvector be a class member ?
	swap_pairs(pairsVector);
	//sort_seq(pairsVector);

}

std::vector< std::pair<unsigned int, unsigned int> > PmergeMe::create_pairs(void)
{
	std::vector< std::pair<unsigned int, unsigned int> > pairsVector;
	for (std::vector<unsigned int>::iterator it = _vector.begin(); it != _vector.end(); it+=2)
		pairsVector.push_back(std::make_pair(*it, *(it + 1)));

	for (std::vector< std::pair<unsigned int, unsigned int> >::iterator it = pairsVector.begin(); it != pairsVector.end(); ++it)
		std::cout << (*it).first << " - " << (*it).second << std::endl;

	return pairsVector;
}

void PmergeMe::swap_pairs(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector)
{
	for (std::vector< std::pair<unsigned int, unsigned int> >::iterator it = pairsVector.begin(); it != pairsVector.end(); ++it)
	{
		if (it->first < it->second)
		{
			int buf = it->second;
			it->second = it->first;
			it->first = buf;
		}
	}
}

// Handle only one pair --> no need to sort the seq
//  Modified recursive insertion sort -->
// void PmergeMe::sort_seq(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector)
// {
// 	for (std::vector< std::pair<unsigned int, unsigned int> >::iterator it = pairsVector.begin(); it != pairsVector.end(); ++it)
// 	{
// 		(*it).first
// 		*(it + 1).first // Look online for insertion sort
// 	}
// }
