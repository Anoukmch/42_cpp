/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:23:23 by amechain          #+#    #+#             */
/*   Updated: 2023/06/20 18:02:02 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

# include <iostream>
# include <stack>
# include <list>

int main()
{
	std::cout << "-- SUBJECT TESTS --" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Last element added : " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Stack size : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << "-- MY TESTS --" << std::endl;
	MutantStack<float> test;

	std::cout << "Adding two entities to stack..." << std::endl;
	test.push(8);
	test.push(7);
	std::cout << "Size of stack : " << test.size() << std::endl;
	std::cout << "Removing one entity from stack..." << std::endl;
	test.pop();
	std::cout << "Accessing stack top : " << test.top() << std::endl;

	std::cout << "Adding few entities to stack..." << std::endl;
	test.push(7);
	test.push(6);
	test.push(5);
	test.push(4);
	std::cout << "Iterating through stack..." << std::endl;
	MutantStack<float>::iterator it_test;
	for(it_test = test.begin(); it_test != test.end(); it_test++)
		std::cout <<  *it_test << std::endl;

	return 0;
}
