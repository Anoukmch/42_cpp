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
// Handle only one pair --> no need to sort the seq

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

void PmergeMe::printer(void) // IMPLEMENT A MORE GENERIC PRINTER
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
	create_pairs(pairsVector); // We can save one line of code ! Shouldnt pairvector be a class member ?
	_vector.clear();
	swap_pairs(pairsVector);
	sort_seq(pairsVector);
	make_main_and_pend(pairsVector);
}

void PmergeMe::make_main_and_pend(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector)
{
	for (std::vector< std::pair<unsigned int, unsigned int> >::iterator it = pairsVector.begin(); it != pairsVector.end(); it++)
		_vector.push_back((*it).first);

	std::vector<unsigned int> pend;
	for (std::vector< std::pair<unsigned int, unsigned int> >::iterator it = pairsVector.begin(); it != pairsVector.end(); it++)
		pend.push_back((*it).second);

	pairsVector.clear();

	std::cout << "\n make_main_and_pend - main : " << std::endl;
	for (std::vector<unsigned int>::iterator it = _vector.begin(); it != _vector.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	std::cout << "\n make_main_and_pend - pend : " << std::endl;
	for (std::vector<unsigned int>::iterator it = pend.begin(); it != pend.end(); it++)
		std::cout << *it << std::endl;
}

void PmergeMe::create_pairs(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector)
{
	for (std::vector<unsigned int>::iterator it = _vector.begin(); it != _vector.end(); it+=2)
		pairsVector.push_back(std::make_pair(*it, *(it + 1)));

	for (std::vector< std::pair<unsigned int, unsigned int> >::iterator it = pairsVector.begin(); it != pairsVector.end(); ++it)
		std::cout << (*it).first << " - " << (*it).second << std::endl;

}

void PmergeMe::swap_pairs(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector)
{
	for (std::vector< std::pair<unsigned int, unsigned int> >::iterator it = pairsVector.begin(); it != pairsVector.end(); ++it)
	{
		if (it->first < it->second)
			swap(it->first, it->second);
	}
	std::cout << "\n swap pairs : " << std::endl;
	for (std::vector< std::pair<unsigned int, unsigned int> >::iterator it = pairsVector.begin(); it != pairsVector.end() ; ++it)
		std::cout << it->first << "-" << it->second << std::endl;
}

void rec_insert(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector, int n)
{
	if (n <= 1)
		return ;

	rec_insert(pairsVector, n-1);

	int j = n-2;
	while (j >= 0 && pairsVector[j].first > pairsVector[j + 1].first ) // Could I write this with a for loop ?
	{
		PmergeMe::swap(pairsVector[j], pairsVector[j + 1]);
		j--;
	}
}

void PmergeMe::sort_seq(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector)
{
	int n = pairsVector.size();
	rec_insert(pairsVector, n);
	std::cout << "\n sort seq : " << std::endl;
	for (std::vector< std::pair<unsigned int, unsigned int> >::iterator it = pairsVector.begin(); it != pairsVector.end() ; ++it)
		std::cout << it->first << "-" << it->second << std::endl;
}
