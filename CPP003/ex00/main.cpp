/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:22:34 by amechain          #+#    #+#             */
/*   Updated: 2023/04/06 17:02:11 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>

int	main(void) {

	std::string trap2Name = "David";
	std::string trap3Name = "Goliath";

	ClapTrap	trap0;
	ClapTrap	trap1(trap0);
	ClapTrap	trap2(trap2Name);
	ClapTrap	trap3(trap3Name);

	trap2.beRepaired(0);
	trap3.beRepaired(0);
	for (int i = 0; i < 11; i++) {
		trap3.attack(trap2Name);
		trap2.takeDamage(0);
	}
	trap2.takeDamage(5);
	trap2.beRepaired(4);
	trap2.takeDamage(12);
	trap2.takeDamage(10);
	trap2.attack(trap3Name);
	trap2.beRepaired(50);
	trap2.takeDamage(10);
	for (int i = 0; i < 9; i++)
		trap2.beRepaired(1);
	return (0);
}



