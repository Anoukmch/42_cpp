/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:32:56 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/09 17:39:42 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define SPAN_SIZE 10

Span::Span() : _n(0) {}

Span::Span( unsigned int N) : _n(N) {}

Span::Span( Span const & src) {
	*this = src; // Replace a vector with another without free, is there leaks ?
}

// Destructors
Span::~Span( void ) {}

// Operator overload
Span & Span::operator=( Span const & src) {
	if ( this != &src ) {
		this->_n = src._n;
		this->_table = src._table;
	}
	return ( *this );
}

void Span::addNumber(int const& value) // const& ? maybe not
{
	if (this->_table.size() == this->_n) // Felix wrote >= N, why ? can it be more than N ?
		throw std::out_of_range("Table reached maximum capacity");
	this->_table.push_back(value);
}

std::vector<int> const& Span::getTable(void) { return _table; }

int Span::shortestSpan()
{
	int shortVal;

	if (this->_table.size() <= 1)
		throw std::exception();

	std::vector<int> sort_table(this->_table);
	std::sort(sort_table.begin(), sort_table.end());
	std::vector<int> diff_table(sort_table); // Copy constructor ?
	std::adjacent_difference(sort_table.begin(), sort_table.end(), diff_table.begin()); // test to print the output

	shortVal = *std::min_element(++(diff_table.begin()), diff_table.end());
	return (shortVal); // test return value unsigned int et envoyer une span negative
}

// Why adjacent_diff return the first element of the input range as first element

int Span::longestSpan()
{
	if (this->_table.size() <= 1)
		throw std::exception();
	return (*std::max_element(this->_table.begin(), this->_table.end()) - *std::min_element(this->_table.begin(), this->_table.end()));
}

// Member function to print the stack

// void Span::fillSpan(void)
// {
// 	std::srand(std::time(NULL));

// 	for (int i = 0; i < SPAN_SIZE ; i++)
// 		_table.push_back(std::rand());
// }

// Or create my own insert function

void Span::fillSpan(std::vector<int>::iterator beg, std::vector<int>::iterator range_beg, std::vector<int>::iterator range_end)
{
	this->_table.insert(beg, range_beg, range_end);
}

// My own insert

void Span::fillSpan()
{
	// Create a table (range_beg > range_end)
	// Fill in with random value

	// Add these value at _table.end() manually, without calling "insert"
	// Using push_back ?

	// OR

	/*
		Receive as argument the three iterators and insert them manually
		You got one pointer to start. And a pointer to the begining of the range.
		Using push_back to add each elements to _table.
	*/

	// OR

	/*
		Receive as argument the first iterator and add the table created (range)
		at the place pointed to by first iterator
	*/
}
