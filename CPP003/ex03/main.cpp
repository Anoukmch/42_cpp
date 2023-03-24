/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:22:34 by amechain          #+#    #+#             */
/*   Updated: 2023/03/22 14:44:12 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <string>

int	main(void) {

	DiamondTrap	*DT0;

	ScavTrap	*ST0;
	ScavTrap	*ST1;

	FragTrap	*FT0;
	FragTrap	*FT1;

	ClapTrap	*CT0;
	ClapTrap	*CT1;
	ClapTrap	*CT2;
	ClapTrap	*CT3;

	DT0 = new DiamondTrap;
	std::cout << "\n";
	ST0 = new DiamondTrap;
	std::cout << "\n";
	ST1 = new ScavTrap;
	std::cout << "\n";
	FT0 = new DiamondTrap;
	std::cout << "\n";
	FT1 = new FragTrap;
	std::cout << "\n";
	CT0 = new DiamondTrap;
	std::cout << "\n";
	CT1 = new ScavTrap;
	std::cout << "\n";
	CT2 = new FragTrap;
	std::cout << "\n";
	CT3 = new ClapTrap;
	std::cout << "\n";

	DT0->attack("DT0");
	ST0->attack("ST0");
	ST1->attack("ST1");
	FT0->attack("FT0");
	FT1->attack("FT1");
	CT0->attack("CT0");
	CT1->attack("CT1");
	CT2->attack("CT2");
	CT3->attack("CT3");

	DT0->guardGate();
	ST0->guardGate();
	ST1->guardGate();

	DT0->highFivesGuys();
	FT0->highFivesGuys();
	FT1->highFivesGuys();

	DT0->whoAmI(); // OK

	return (0);
}
