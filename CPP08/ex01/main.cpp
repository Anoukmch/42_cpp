/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:23:23 by amechain          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/15 21:59:58 by anoukmechai      ###   ########.fr       */
=======
/*   Updated: 2023/06/09 17:30:55 by amechain         ###   ########.fr       */
>>>>>>> 748e1922938867e4bfa606f82e8d4b4f86bb2a6d
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void )
{
	Span span = Span(5);

	span.addNumber(6);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);

	std::cout << span.shortestSpan() << std::endl;
<<<<<<< HEAD
}
=======
	std::cout << span.longestSpan() << std::endl;

	span.getTable().insert(getTable.end(), ...) // Would this work ?
}

/*
A member function that takes a range of iterators =
Function( container.begin(), container.end() )

1. Call insert on std::vector _table and a range
2.

Create my own insert.
insert(container.end())
{

	std::vector<int> range;
	std::list<int>::iterator it;

	for (it = container.end() ; it < (container.end() + SPAN_SIZE); it++)
		*it.push_back(std::rand());

	for (int i = 0; i < SPAN_SIZE ; i++)
		push_back(srand);
}
at container.end(), iterates.
and push.back each elements on std::vector, from range.begin() to range.end()

OR, recreate insert like normal (std::vector, range, range);
*/
>>>>>>> 748e1922938867e4bfa606f82e8d4b4f86bb2a6d
