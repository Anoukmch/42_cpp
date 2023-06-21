/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:23:23 by amechain          #+#    #+#             */
/*   Updated: 2023/06/21 12:26:40 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
# include <deque>

int main( void )
{
	try
	{
		Span span = Span(5);

		std::cout << "Creating span using addNumber..." << std::endl;
		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);

		std::cout << "Printing span..." << std::endl;
		std::cout << span << std::endl << std::endl;

		std::cout << "Shortest span : " << span.shortestSpan() << std::endl;
		std::cout << "Longest span : " << span.longestSpan() << std::endl << std::endl;

		std::cout << "Creating span of 4..." << std::endl;
		Span solospan(4);
		std::cout << "Trying to perfom operation on empty span..." << std::endl;
		solospan.shortestSpan();
	}
	catch(const std::exception& e) { std::cerr << e.what() << std::endl; }

	try
	{
		Span solospan(4);
		solospan.addNumber(5);
		solospan.addNumber(4);
		solospan.addNumber(1);
		solospan.addNumber(15);
		std::cout << "Trying to add a 5th element..." << std::endl;
		solospan.addNumber(20);
	}
	catch(const std::exception& e) { std::cerr << e.what() << std::endl; }

	try
	{
		std::cout << std::endl;

		std::cout << "Creating span of 10..." << std::endl;
		Span rangespan(10);
		std::srand(std::time(NULL));
		std::deque<int> range;
		for (int i = 0; i < 6 ; i++)
			range.push_back(std::rand());
		std::cout << "Adding a range of 6..." << std::endl;
		rangespan.fillSpan<std::deque<int> >(range.begin(), range.end());
		std::cout << "Span contains : " << rangespan.getTable().size() << std::endl;

		std::cout << "Adding a range of 6 again..." << std::endl;
		rangespan.fillSpan<std::deque<int> >(range.begin(), range.end());
	}
	catch(const std::exception& e) { std::cerr << e.what() << std::endl; }

}
