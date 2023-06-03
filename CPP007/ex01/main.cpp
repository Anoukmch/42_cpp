/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:23:23 by amechain          #+#    #+#             */
/*   Updated: 2023/06/03 15:06:37 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void ) {
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int array_length = (int)(sizeof(array)/sizeof(array[0]));

	std::cout << "Array before iter : " << std::endl;
	for (int i = 0; i < array_length; i++)
		std::cout << array[i] << std::endl;
	::iter(array, array_length, ::plus<int&>);
	std::cout << "\nArray after iter : " << std::endl;
	for (int i = 0; i < array_length; i++)
		std::cout << array[i] << std::endl;
}

