/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:28 by mcombeau          #+#    #+#             */
/*   Updated: 2023/06/21 14:18:18 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::list<int> l;
	std::vector<int> v;
	std::deque<int> d;

	l.push_back(0);
	l.push_back(0);
	l.push_back(9);
	l.push_back(0);

	v.push_back(0);
	v.push_back(9);
	v.push_back(0);
	v.push_back(0);

	d.push_back(0);
	d.push_back(0);
	d.push_back(0);
	d.push_back(9);

	std::list<int>::iterator it_l;
	std::vector<int>::iterator it_v;
	std::deque<int>::iterator it_d;

	std::cout << "-- Printing the containers --" << std::endl;
	for (it_l = l.begin(); it_l != l.end(); it_l++)
		std::cout << "list : ["<< *it_l << "]" << std::endl;
	for (it_v = v.begin(); it_v != v.end(); it_v++)
		std::cout << "vector : ["<< *it_v << "]" << std::endl;
	for (it_d = d.begin(); it_d != d.end(); it_d++)
		std::cout << "dector : ["<< *it_d << "]" << std::endl;

	std::cout << std::endl;
	std::cout << "-- Testing the function --" << std::endl;
	try
	{
		it_l = easyfind(l, 9);
		std::cout << "Found " << *it_l << " in list with success!" << std::endl;
		it_v = easyfind(v, 9);
		std::cout << "Found " << *it_v << " in vector with success!" << std::endl;
		it_d = easyfind(d, 9);
		std::cout << "Found " << *it_d << " in deque with success!" << std::endl;
	}
	catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
	try
	{
		it_l = easyfind(l, 100);
		std::cout << "Found " << *it_l << " in list with success!" << std::endl;
	}
	catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
}

