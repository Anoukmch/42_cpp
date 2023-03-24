/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:59:01 by amechain          #+#    #+#             */
/*   Updated: 2023/03/23 16:54:00 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ANIMAL_NBR 10

int	main(void)
{
	Animal *_animal[ANIMAL_NBR];

	for (int i = 0; i < ANIMAL_NBR ; i++)
	{
		std::cout << "Constructor - Animal " << i + 1 << " : " << std::endl;
		if (i < (ANIMAL_NBR / 2))
			_animal[i] = new Dog();
		else
			_animal[i] = new Cat();
		std::cout << std::endl;
	}
	for (int i = 0; i < ANIMAL_NBR ; i++)
	{
		std::cout << "Destructor - Animal " << i + 1 << " : " << std::endl;
		delete _animal[i];
		std::cout << std::endl;
	}
	return 0;
}

// Check order of destructors (brain, cat, animal)
// Why is it calling the animal destructor all the time ?

