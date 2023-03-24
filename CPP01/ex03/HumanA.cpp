/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:29:06 by amechain          #+#    #+#             */
/*   Updated: 2023/01/30 15:49:34 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// if no pointer or reference, _weaponA becomes a copy of weapon, so it is not related to "club" in any way
// creating a reference means _weaponA is now an alias of weapon
// sending "club" to HumanA as a reference means weapon is an alias of club

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
