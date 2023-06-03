/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:23:23 by amechain          #+#    #+#             */
/*   Updated: 2023/06/03 16:06:05 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base * generate(void)
{
	int r = std::rand() % 3;
	Base *base;

	if (r == 0)
		base = new (A);
	else if (r == 1)
		base = new (B);
	else
		base = new (C);
	return (base);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type of the object as pointer : A | ";
	else if (dynamic_cast<B*>(p))
		std::cout << "Type of the object as pointer : B | ";
	else if (dynamic_cast<C*>(p))
		std::cout << "Type of the object as pointer : C | ";
	else
		std::cout << "Type of the object as pointer : Unknown | ";
}

void identify(Base& p)
{
	char letter;
	try
	{
		(void)dynamic_cast<A&>(p);
		letter = 'A';
	}
	catch (std::exception & e) {}
	try
	{
		if (!letter)
		{
			(void)dynamic_cast<B&>(p);
			letter = 'B';
		}
	}
	catch (std::exception & e) {}
	try
	{
		if (!letter)
		{
			(void)dynamic_cast<C&>(p);
			letter = 'C';
		}
	}
	catch (std::exception & e) { }
	if (letter)
		std::cout << "Type of the object as reference : " << letter << std::endl;
	else
		std::cout << "Type of the object as reference : Unknown" << std::endl;

}

int	main()
{
	Base *p;
	std::srand(std::time(NULL));

	for (int i = 0; i < 15 ; i++)
	{
		p = generate();
		identify(p);
		identify(*p);
		delete (p);
	}

}
