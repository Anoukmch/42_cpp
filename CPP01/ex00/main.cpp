/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:48:51 by mcombeau          #+#    #+#             */
/*   Updated: 2023/04/06 18:22:45 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

int	main(void) {
	// Heap
	Zombie	*firstZombie = newZombie("Zombie_heap 1");
	Zombie	*secondZombie = newZombie("Zombie_heap 2" );
	Zombie	*thirdZombie = newZombie("Zombie_heap 3");

	// Stack
	randomChump("Zombie_stack 1");
	randomChump("Zombie_stack 2");
	randomChump("Zombie_stack 3");

	firstZombie->announce();
	delete firstZombie;
	secondZombie->announce();
	thirdZombie->announce();
	delete thirdZombie;
	delete secondZombie;
	system("leaks ex00");
	return ( 0 );
}
