/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:32:56 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/07 18:28:06 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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

int Span::shortestSpan()
{
	int shortVal; 
	
	if (this->_table.size() <= 1)
		throw std::exception(); 

	std::vector<int> ajd_diff(this->_table); // copy constructor ?
	std::adjacent_difference(_table.begin(), _table.end(), ajd_diff.begin()); // test to print the output
	
	for (std::vector<int>::iterator it = ajd_diff.begin(); it != ajd_diff.end(); ++it) {
        *it = abs(*it);
    }
	shortVal = *std::min_element(++(ajd_diff.begin()), ajd_diff.end());
	return (shortVal); // test return value unsigned int et envoyer une span negative 
}

// why adjacent_diff return the first element of the input range as first element

int Span::longestSpan()
{
	if (this->_table.size() <= 1)
		throw std::exception();
	return (*std::max_element(this->_table.begin(), this->_table.end()) - *std::min_element(this->_table.begin(), this->_table.end()));
}

// Member function to print the stack 
