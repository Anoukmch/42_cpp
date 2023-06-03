/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:23:23 by amechain          #+#    #+#             */
/*   Updated: 2023/06/03 17:09:36 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Cat.hpp"

template <typename T>
void printTable(Array<T> & array)
{
	for (int i = 0 ; i < array.size() ; i++)
	{
		std::cout << "[index." << i << "] : ";
		std::cout << "[" << array[i] << "] " << std::endl;
	}
	std::cout << std::endl;
}

int main( void ) // Const instance ?
{
	const Array<const int> test(5);

	std::cout << test[0] << std::endl;
	std::cout << "-- CONSTRUCTORS TESTS -- \n" << std::endl;
	std::cout << "Creating a default array called i..." << std::endl;
	Array<int> i;
	std::cout << "Creating an overloaded array called i_ovload..." << std::endl;
	Array<int> i_ovload(5);
	std::cout << "Creating a copy of i_ovload called i_copy..." << std::endl;
	Array<int> i_copy(i_ovload);


	std::cout << "\n-- OPERATORS TESTS -- \n" << std::endl;
	std::cout << "Filling in i_ovload three times..." << std::endl;
	i_ovload[0] = 1;
	i_ovload[1] = 2;
	i_ovload[2] = 3;
	std::cout << "Printing i_ovload..." << std::endl;
	printTable(i_ovload);

	std::cout << "Assigning i with i_ovload..." << std::endl;
	i = i_ovload;
	std::cout << "Printing i..." << std::endl;
	printTable(i);

	std::cout << "\n-- DEEP COPIES TESTS -- \n" << std::endl;
	std::cout << "Creating a copy of i_ovload called i_copy_overload..." << std::endl;
	Array<int> i_copy_overload(i_ovload);
	std::cout << "Printing i_copy_overload..." << std::endl;
	printTable(i_copy_overload);

	std::cout << "Printing i_ovload..." << std::endl;
	printTable(i_ovload);

	std::cout << "Changing the first value of i_ovload..." << std::endl;
	i_ovload[0] = 10;

	std::cout << "Printing i_copy_overload..." << std::endl;
	printTable(i_copy_overload);

	std::cout << "Printing i_ovload..." << std::endl;
	printTable(i_ovload);

	std::cout << "Changing the second value of i_copy_overload..." << std::endl;
	i_copy_overload[1] = 20;

	std::cout << "Printing i_copy_overload..." << std::endl;
	printTable(i_copy_overload);

	std::cout << "Printing i_ovload..." << std::endl;
	printTable(i_ovload);

	std::cout << "\n-- SIZE() TESTS -- \n" << std::endl;
	std::cout << "Size of array i : " << i.size() << std::endl;

	std::cout << "\n-- OVERFLOWS TESTS -- \n" << std::endl;
	std::cout << "Trying to access i[10]..." << std::endl;

	try { i[10] = 1; }
	catch(const std::exception& e) { std::cerr << e.what() << " : Out of bound index" << std::endl; }

	std::cout << "\nWhat if n is not valid ?" << std::endl;
	try { Array<int> i_test(-5); }
	catch(const std::exception& e) { std::cerr << e.what() << " : The size of the array is not valid" << std::endl; }


	std::cout << "\n-- COMPLEX TYPE TESTS -- \n" << std::endl;
	Array<Cat> c;
	Array<Cat> c_ovload(1);

	c = c_ovload;
	std::cout << "\n-- DESTRUCTOR TESTS -- \n" << std::endl;
}
