/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:59:01 by amechain          #+#    #+#             */
/*   Updated: 2023/04/07 16:55:45 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ANIMAL_NBR 10

int	main(void)
{
	const Animal* j = new Cat();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	delete j;
	delete i;

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

	Cat cat1;
	std::cout << std::endl;
	cat1.setIdea(0, "ying");
	cat1.setIdea(1, "yang");
	cat1.setIdea(2, "yong");
	std::cout << "Cat 1 idea :" << std::endl;
	for (int i = 0; i < 3 ; i++)
		std::cout << cat1.getIdea(i) << std::endl;
	std::cout << std::endl;

	std::cout << "Deep copy using assignement operator : \n" << std::endl;
	Cat cat2;
	cat2 = cat1;
	std::cout << std::endl;
	std::cout << "Cat 2 idea :" << std::endl;
	for (int i = 0; i < 3 ; i++)
		std::cout << cat2.getIdea(i) << std::endl;
	std::cout << std::endl;

	std::cout << "Deep copy using copy constructor : \n" << std::endl;
	Cat cat3(cat1);
	std::cout << std::endl;
	std::cout << "Cat 3 idea :" << std::endl;
	for (int i = 0; i < 3 ; i++)
		std::cout << cat3.getIdea(i) << std::endl;
	std::cout << std::endl;

	std::cout << "Now the three cats are independents : \n" << std::endl;
	std::cout << "~ Changing idea of cat 1 ~ \n" << std::endl;
	cat1.setIdea(0, "heyhey");
	std::cout << "Cat 1 idea :" << std::endl;
	for (int i = 0; i < 3 ; i++)
		std::cout << cat1.getIdea(i) << std::endl;
	std::cout << std::endl;
	std::cout << "Cat 2 idea :" << std::endl;
	for (int i = 0; i < 3 ; i++)
		std::cout << cat2.getIdea(i) << std::endl;
	std::cout << std::endl;
	std::cout << "Cat 3 idea :" << std::endl;
	for (int i = 0; i < 3 ; i++)
		std::cout << cat3.getIdea(i) << std::endl;
	std::cout << std::endl;

	std::cout << "~ Changing idea of cat 2 ~ \n" << std::endl;
	cat2.setIdea(2, "I'm an independant cat!");
	std::cout << "Cat 1 idea :" << std::endl;
	for (int i = 0; i < 3 ; i++)
		std::cout << cat1.getIdea(i) << std::endl;
	std::cout << std::endl;
	std::cout << "Cat 2 idea :" << std::endl;
	for (int i = 0; i < 3 ; i++)
		std::cout << cat2.getIdea(i) << std::endl;
	std::cout << std::endl;
	std::cout << "Cat 3 idea :" << std::endl;
	for (int i = 0; i < 3 ; i++)
		std::cout << cat3.getIdea(i) << std::endl;
	std::cout << std::endl;

	std::cout << "~ Changing idea of cat 3 ~ \n" << std::endl;
	cat3.setIdea(2, "I'm ALSO an independant cat!");
	std::cout << "Cat 1 idea :" << std::endl;
	for (int i = 0; i < 3 ; i++)
		std::cout << cat1.getIdea(i) << std::endl;
	std::cout << std::endl;
	std::cout << "Cat 2 idea :" << std::endl;
	for (int i = 0; i < 3 ; i++)
		std::cout << cat2.getIdea(i) << std::endl;
	std::cout << std::endl;
	std::cout << "Cat 3 idea :" << std::endl;
	for (int i = 0; i < 3 ; i++)
		std::cout << cat3.getIdea(i) << std::endl;
	std::cout << std::endl;
	return 0;
}
