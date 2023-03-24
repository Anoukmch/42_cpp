/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:59:01 by amechain          #+#    #+#             */
/*   Updated: 2023/03/22 17:06:35 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	const WrongCat* wac = new WrongCat();
	const WrongAnimal* wa = new WrongAnimal();

	std::cout << d->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	d->makeSound();
	c->makeSound();
	meta->makeSound();
	wac->makeSound();
	wa->makeSound();

	delete meta;
	delete d;
	delete c;
	delete wac;
	delete wa;

	return 0;
}

// destructors on pointers
// why is it calling the animal destructor all the time ?
