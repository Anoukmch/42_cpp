/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:23:23 by amechain          #+#    #+#             */
/*   Updated: 2023/06/07 18:33:43 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void ) 
{
	Span span(5);

	span.addNumber(34);
	span.addNumber(22);
	span.addNumber(10);
	span.addNumber(20);
	span.addNumber(24);
	
	std::cout << span.longestSpan() << std::endl;
	std::cout << span.shortestSpan() << std::endl;
}

10
20
24
25
34