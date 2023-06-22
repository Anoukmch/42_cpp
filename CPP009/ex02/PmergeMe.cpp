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

unsigned int isValidExpression(std::string const & number);

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
		_deque.push_back(nbr);
	}
	if (_vector.size() == 1)
		throw std::logic_error("Program requires at least 2 arguments in a sequence");
	std::vector<unsigned int> sort_table(_vector);
	std::sort(sort_table.begin(), sort_table.end());
	if (_vector == sort_table)
		throw std::logic_error("Array is already sorted");
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
		_vector = src._vector;
		_odd = src._odd;
		_jacobSeq = src._jacobSeq;
		_deque = src._deque;
	}
	return ( *this );
}

// UTILS

int jacobsthal(unsigned int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

unsigned int isValidExpression(std::string const & number)
{
	std::istringstream iss(number);
	float nbr;

	iss >> nbr;
	if (nbr < 0 || iss.fail() || nbr > INT_MAX)
		throw std::logic_error("Wrong input format");
	if (!iss.eof())
	{
		iss >> std::ws;
		if (!iss.eof())
			throw std::logic_error("Wrong input format");
	}
	return (nbr);
}

void PmergeMe::timer(std::clock_t vecTime, std::clock_t deqTime)
{
	double clock_per_ms = static_cast<double>(CLOCKS_PER_SEC) / 1000;

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : ";
	std::cout << std::fixed;
	std::cout.precision( 6 );
	std::cout << vecTime / clock_per_ms << " ms" << std::endl;

	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : ";
	std::cout << std::fixed;
	std::cout.precision( 6 );
	std::cout << deqTime / clock_per_ms << " ms" << std::endl;
}

void PmergeMe::print_vec()
{
	std::cout << "-- as std::vector :\t";
	for (std::vector<unsigned int>::iterator it = _vector.begin(); it != _vector.end() ; ++it)
		std::cout << "[" << *it << ']';
	std::cout << std::endl;
}

void PmergeMe::print_deq()
{
	std::cout << "-- as std::deque :\t";
	for (std::deque<unsigned int>::iterator it = _deque.begin(); it != _deque.end() ; ++it)
		std::cout << "[" << *it << ']';
	std::cout << std::endl;
}

// SORTING ALGORITHM

void PmergeMe::sort_menu(void)
{
	std::cout << "Before: " << std::endl;
	print_vec();
	print_deq();
	std::cout << std::endl;

	std::clock_t start = std::clock();
	sort_vec();
	std::clock_t vecTime = std::clock() - start;

	start = std::clock();
	sort_deq();
	std::clock_t deqTime = std::clock() - start;

	std::cout << "After: " << std::endl;
	print_vec();
	print_deq();
	std::cout << std::endl;

	timer(vecTime, deqTime);
}

// VECTOR

void PmergeMe::sort_vec(void)
{
	if (_vector.size() % 2 != 0)
	{
		_odd = _vector.back();
		_vector.pop_back();
	}

	std::vector< std::pair<unsigned int, unsigned int> > pairsVector;
	std::vector<unsigned int> pend;
	std::vector<unsigned int> indexSequence;
	create_pairs(pairsVector);
	_vector.clear();
	swap_pairs(pairsVector);
	sort_seq(pairsVector);
	make_main_and_pend(pairsVector, pend);
	create_jac_seq(pend);
	create_full_insert_sec(pend, indexSequence);
	insert_pend(pend, indexSequence);
}

bool findInt(unsigned int i, std::vector<unsigned int> indexSeq)
{
	for (std::vector<unsigned int>::iterator it = indexSeq.begin(); it != indexSeq.end() ; ++it)
	{
		if (i == *it)
			return 1;
	}
	return 0;
}

void rec_insert(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector, int n)
{
	if (n <= 1)
		return ;

	rec_insert(pairsVector, n-1);

	int j = n-2;
	while (j >= 0 && pairsVector[j].first > pairsVector[j + 1].first )
	{
		PmergeMe::swap(pairsVector[j], pairsVector[j + 1]);
		j--;
	}
}

int PmergeMe::bisect_vec(unsigned int x ) // change and understand this
{
	int lo = 0;
	int hi = _vector.size();

	while ( lo < hi )
	{
		int mid = ( lo + hi ) / 2;
		if ( x  < _vector[mid] )
			hi = mid;
		else
			lo = mid + 1;
	}
	return ( lo );
}

void PmergeMe::create_pairs(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector)
{
	for (std::vector<unsigned int>::iterator it = _vector.begin(); it != _vector.end(); it+=2)
		pairsVector.push_back(std::make_pair(*it, *(it + 1)));
}

void PmergeMe::swap_pairs(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector)
{
	for (std::vector< std::pair<unsigned int, unsigned int> >::iterator it = pairsVector.begin(); it != pairsVector.end(); ++it)
	{
		if (it->first < it->second)
			swap(it->first, it->second);
	}
}

void PmergeMe::sort_seq(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector)
{
	int n = pairsVector.size();
	rec_insert(pairsVector, n);
}

void PmergeMe::make_main_and_pend(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector, std::vector<unsigned int> & pend) // TEST THIS
{
	for (std::vector< std::pair<unsigned int, unsigned int> >::iterator it = pairsVector.begin(); it != pairsVector.end(); it++)
		_vector.push_back((*it).first);

	for (std::vector< std::pair<unsigned int, unsigned int> >::iterator it = pairsVector.begin() ; it != pairsVector.end(); it++)
		pend.push_back((*it).second);

	pairsVector.clear();
}

void PmergeMe::create_jac_seq(std::vector<unsigned int> & pend)
{
	int index = 3; // why does it need to start at 3 ?
	int pend_size = pend.size();

	while(jacobsthal(index) < pend_size - 1)
	{
		_jacobSeq.push_back(jacobsthal(index));
		index++;
	}
}

void PmergeMe::create_full_insert_sec(std::vector<unsigned int> & pend, std::vector<unsigned int> & indexSequence)
{
	unsigned int i = 1;

	std::string last = "default";
	indexSequence.push_back( 1 );
	while (i < pend.size())
	{
		if (_jacobSeq.size() != 0 && last != "j")
		{
			indexSequence.push_back(_jacobSeq[0]);
			_jacobSeq.erase(_jacobSeq.begin());
			last = "j";
		}
		else
		{
			if (findInt(i, indexSequence))
				i++;
			indexSequence.push_back(i);
			last = "non-j";
		}
		i++;
	}
}

void PmergeMe::insert_pend(std::vector<unsigned int> & pend, std::vector<unsigned int> & indexSequence)
{
	for (std::vector<unsigned int>::iterator it = indexSequence.begin() ; it != indexSequence.end(); it++)
	{
		int item = pend[*it - 1];
		int index = bisect_vec( item );
		_vector.insert(_vector.begin() + index, item);
	}
	if (_odd > 0)
	{
		int index = bisect_vec( _odd );
		_vector.insert(_vector.begin() + index, _odd);
	}
}

// DEQUE

void PmergeMe::sort_deq(void)
{
	if (_deque.size() % 2 != 0)
	{
		_odd = _deque.back();
		_deque.pop_back();
	}

	std::deque< std::pair<unsigned int, unsigned int> > pairsDeque;
	std::deque<unsigned int> pend;
	std::deque<unsigned int> indexSequence;
	create_pairs(pairsDeque);
	_deque.clear();
	swap_pairs(pairsDeque);
	sort_seq(pairsDeque);
	make_main_and_pend(pairsDeque, pend);
	create_jac_seq(pend);
	create_full_insert_sec(pend, indexSequence);
	insert_pend(pend, indexSequence);
}

bool findInt(unsigned int i, std::deque<unsigned int> indexSeq)
{
	for (std::deque<unsigned int>::iterator it = indexSeq.begin(); it != indexSeq.end() ; ++it)
	{
		if (i == *it)
			return 1;
	}
	return 0;
}

void rec_insert(std::deque< std::pair<unsigned int, unsigned int> > & pairsDeque, int n)
{
	if (n <= 1)
		return ;

	rec_insert(pairsDeque, n-1);

	int j = n-2;
	while (j >= 0 && pairsDeque[j].first > pairsDeque[j + 1].first )
	{
		PmergeMe::swap(pairsDeque[j], pairsDeque[j + 1]);
		j--;
	}
}

int PmergeMe::bisect_deq(unsigned int x ) // change and understand this
{
	int lo = 0;
	int hi = _deque.size();

	while ( lo < hi )
	{
		int mid = ( lo + hi ) / 2;
		if ( x  < _deque[mid] )
			hi = mid;
		else
			lo = mid + 1;
	}
	return ( lo );
}

void PmergeMe::create_pairs(std::deque< std::pair<unsigned int, unsigned int> > & pairsDeque)
{
	for (std::deque<unsigned int>::iterator it = _deque.begin(); it != _deque.end(); it+=2)
		pairsDeque.push_back(std::make_pair(*it, *(it + 1)));

	// std::cout << "create pairs : " << std::endl;
	// for (std::deque< std::pair<unsigned int, unsigned int> >::iterator it = pairsDeque.begin(); it != pairsDeque.end(); ++it)
	// 	std::cout << (*it).first  << " - " << (*it).second << std::endl;
}

void PmergeMe::swap_pairs(std::deque< std::pair<unsigned int, unsigned int> > & pairsDeque)
{
	for (std::deque< std::pair<unsigned int, unsigned int> >::iterator it = pairsDeque.begin(); it != pairsDeque.end(); ++it)
	{
		if (it->first < it->second)
			swap(it->first, it->second);
	}
	// std::cout << "swap pairs : " << std::endl;
	// for (std::deque< std::pair<unsigned int, unsigned int> >::iterator it = pairsDeque.begin(); it != pairsDeque.end(); ++it)
	// 	std::cout << (*it).first  << " - " << (*it).second << std::endl;
}

void PmergeMe::sort_seq(std::deque< std::pair<unsigned int, unsigned int> > & pairsDeque)
{
	int n = pairsDeque.size();
	rec_insert(pairsDeque, n);
	// std::cout << "sort seq : " << std::endl;
	// for (std::deque< std::pair<unsigned int, unsigned int> >::iterator it = pairsDeque.begin(); it != pairsDeque.end(); ++it)
	// 	std::cout << (*it).first  << " - " << (*it).second << std::endl;
}

void PmergeMe::make_main_and_pend(std::deque< std::pair<unsigned int, unsigned int> > & pairsDeque, std::deque<unsigned int> & pend) // TEST THIS
{
	for (std::deque< std::pair<unsigned int, unsigned int> >::iterator it = pairsDeque.begin(); it != pairsDeque.end(); it++)
		_deque.push_back((*it).first);

	for (std::deque< std::pair<unsigned int, unsigned int> >::iterator it = pairsDeque.begin() ; it != pairsDeque.end(); it++)
		pend.push_back((*it).second);

	pairsDeque.clear();

	// std::cout << "make main : " << std::endl;
	// for (std::deque<unsigned int>::iterator it = _deque.begin(); it != _deque.end(); ++it)
	// 	std::cout << (*it) << std::endl;

	// 	std::cout << "make pend : " << std::endl;
	// for (std::deque<unsigned int>::iterator it = pend.begin(); it != pend.end(); ++it)
	// 	std::cout << (*it)  << std::endl;
}

void PmergeMe::create_jac_seq(std::deque<unsigned int> & pend)
{
	int index = 3; // why does it need to start at 3 ?
	int pend_size = pend.size();

	while(jacobsthal(index) < pend_size - 1)
	{
		_jacobSeq.push_back(jacobsthal(index));
		index++;
	}
}

void PmergeMe::create_full_insert_sec(std::deque<unsigned int> & pend, std::deque<unsigned int> & indexSequence)
{
	unsigned int i = 1;

	std::string last = "default";
	indexSequence.push_back( 1 );
	while (i < pend.size())
	{
		if (_jacobSeq.size() != 0 && last != "j")
		{
			indexSequence.push_back(_jacobSeq[0]);
			_jacobSeq.erase(_jacobSeq.begin());
			last = "j";
		}
		else
		{
			if (findInt(i, indexSequence))
				i++;
			indexSequence.push_back(i);
			last = "non-j";
		}
		i++;
	}
	// std::cout << "create full seq : " << std::endl;
	// for (std::deque< unsigned int>::iterator it = indexSequence.begin(); it != indexSequence.end(); ++it)
	// 	std::cout << (*it)  << std::endl;
}

void PmergeMe::insert_pend(std::deque<unsigned int> & pend, std::deque<unsigned int> & indexSequence)
{
	for (std::deque<unsigned int>::iterator it = indexSequence.begin() ; it != indexSequence.end(); it++)
	{
		int item = pend[*it - 1];
		int index = bisect_deq( item );
		_deque.insert(_deque.begin() + index, item);
	}
	if (_odd > 0)
	{
		int index = bisect_deq( _odd );
		_deque.insert(_deque.begin() + index, _odd);
	}
	// std::cout << "final : " << std::endl;
	// for (std::deque< unsigned int>::iterator it = _deque.begin(); it != _deque.end(); ++it)
	// 	std::cout << (*it)  << std::endl;
}


