/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:29:06 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 11:40:04 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructors
HumanA::HumanA(std::string const& name, Weapon& weapon) : _weaponA(weapon), _name(name) {}

// Destructor
HumanA::~HumanA() {}

// Member functions
void HumanA::attack(void) {
	std::cout << _name << " attacks with their ";
	if (_weaponA.getType() == "")
		std::cout << "default weapon\n";
	else
		std::cout << _weaponA.getType() << "\n"; }
