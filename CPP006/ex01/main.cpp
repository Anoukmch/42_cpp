/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:23:23 by amechain          #+#    #+#             */
/*   Updated: 2023/05/30 11:44:02 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	Data data;
	data.i = 10;

	uintptr_t i = Serializer::serialize(&data);
	Data * d = Serializer::deserialize(i);

	std::cout << "Before serialization : \n" << data << std::endl;
	if (&data == d)
		std::cout << "\nSeralization success ! " << std::endl << std::endl;
	else
		std::cout << "\nSeralization fail ! " << std::endl << std::endl;
	std::cout << "Pointer as integer : " << i << std::endl << std::endl;
	std::cout << "After serialization : \n" << *d << std::endl;

}
