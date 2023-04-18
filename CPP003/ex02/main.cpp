/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:22:34 by amechain          #+#    #+#             */
/*   Updated: 2023/04/06 17:57:07 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <string>

int	main(void) {

	std::string trap2Name = "David";
	std::string trap3Name = "Goliath";

	FragTrap	trap1;
	FragTrap	trap2(trap2Name);
	FragTrap	trap3(trap3Name);
	FragTrap	trap4(trap2);

	trap2.attack(trap3Name);
	trap2.highFivesGuys();
	trap2.takeDamage(101);
	trap2.highFivesGuys();
	trap2.attack(trap3Name);
	trap2.beRepaired(1000);
	return (0);
}
