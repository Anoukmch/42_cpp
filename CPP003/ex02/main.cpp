/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:22:34 by amechain          #+#    #+#             */
/*   Updated: 2023/03/22 13:43:13 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

int	main(void) {

	std::string trap2Name = "David";
	std::string trap3Name = "Goliath";

	ScavTrap	trap1;
	ScavTrap	trap2(trap2Name);
	ScavTrap	trap3(trap3Name);
	ScavTrap	trap4(trap2);
	FragTrap	hp;

	trap2.attack(trap3Name);
	trap2.guardGate();
	trap2.takeDamage(101);
	trap2.guardGate();
	trap2.attack(trap3Name);
	trap2.beRepaired(1000);
	return (0);
}

// How can I call a constructor copy with an overload ?

