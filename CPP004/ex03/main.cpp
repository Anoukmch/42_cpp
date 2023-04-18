/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:36:57 by amechain          #+#    #+#             */
/*   Updated: 2023/04/07 21:09:22 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "My own test : " << std::endl;
	Character yo("yo");
	Character victim("victim");
	yo.equip(new Ice());
	yo.equip(new Cure());
	yo.equip(new Ice());
	yo.equip(new Cure());
	yo.unequip(2);
	yo.unequip(10);
	yo.use(1, victim);
	yo.use(0, victim);

	MateriaSource test;
	test.learnMateria(new Cure());
	test.createMateria("wrong materia");
	return 0;
}
