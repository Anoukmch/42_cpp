/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:22:34 by amechain          #+#    #+#             */
/*   Updated: 2023/04/12 14:01:12 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {

DiamondTrap	test;
	DiamondTrap	*DT;
	ScavTrap	*ST;
	FragTrap	*FT;
	ClapTrap	*CT;

	DT = new DiamondTrap("Diamond");
	std::cout << "\n";
	ST = new ScavTrap("Scavy");
	std::cout << "\n";
	FT = new FragTrap("Fragy");
	std::cout << "\n";
	CT = new ClapTrap("Clapy4");
	std::cout << "\n";

	DT->attack("DT0");
	ST->attack("ST0");
	FT->attack("ST1");
	CT->attack("FT0");

	//DT->guardGate();
	ST->guardGate();

	DT->highFivesGuys();
	FT->highFivesGuys();

	DT->whoAmI();
	DT->test();
	std::cout << "\n";
	delete DT;
	std::cout << "\n";
	delete ST;
	std::cout << "\n";
	delete FT;
	std::cout << "\n";
	delete CT;
	std::cout << "\n";
	return (0);
}
