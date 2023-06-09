/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:23:23 by amechain          #+#    #+#             */
/*   Updated: 2023/06/08 18:05:03 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "MutantStack.hpp"

# include <iostream>
# include <stack>
# include <list>

int main( void ) {

	std::list<int> l;
	std::list<int>::iterator it;

	for (it = l.begin(); it != l.end(); it++)
		std::cout << *it << std::endl;

	std::stack<int> s; // = MutantStack<int> m;
	std::stack<int>::iterator test; // = MutantStack<int>::iterator test2;


	// for (test = s.begin(); test != s.end(); test++)
	// 	std::cout << *test << std::endl;

}

// std::stack<int> s , means create an object.
// It's a stack full of int. By default a deque, since we did not precise C.
// I cannot call begin() and end() on this object. Unlike vector, list, deque...

// std::stack<int>::iterator test , is like Form::NotFound.
// iterator is a class. 
