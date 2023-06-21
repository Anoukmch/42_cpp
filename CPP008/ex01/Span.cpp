/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:32:56 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/21 12:17:54 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define SPAN_SIZE 10

Span::Span() : _n(0) {}

Span::Span( unsigned int N) : _n(N) {}

Span::Span( Span const & src) {
	*this = src;
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

void Span::addNumber(int const& value)
{
	if (this->_table.size() == this->_n)
		throw std::out_of_range("Error : Table reached maximum capacity");
	this->_table.push_back(value);
}

std::vector<int> const& Span::getTable(void) const { return _table; }

int Span::shortestSpan()
{
	int shortVal;

	if (this->_table.size() <= 1)
		throw std::logic_error("Error : Not enough element to perfom operation");

	std::vector<int> sort_table(this->_table);
	std::sort(sort_table.begin(), sort_table.end());
	std::vector<int> diff_table(sort_table);
	std::adjacent_difference(sort_table.begin(), sort_table.end(), diff_table.begin());

	shortVal = *std::min_element(++(diff_table.begin()), diff_table.end());
	return (shortVal);
}

int Span::longestSpan()
{
	if (this->_table.size() <= 1)
		throw std::logic_error("Error : Not enough element to perfom operation");
	return (*std::max_element(this->_table.begin(), this->_table.end()) - *std::min_element(this->_table.begin(), this->_table.end()));
}

std::ostream &operator<<( std::ostream &flux, Span const& var ) {
	for (std::vector<int>::const_iterator it = var.getTable().begin(); it != var.getTable().end(); it++)
		std::cout << "["<< *it << "]";
	return ( flux );
}
