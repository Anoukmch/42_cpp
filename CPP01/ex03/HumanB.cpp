/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:29:36 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 11:52:01 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructors
HumanB::HumanB() : _weaponB(NULL), _name("default name B") {}
HumanB::HumanB(std::string const& name) : _weaponB(NULL), _name(name) {}

// Destructor
HumanB::~HumanB() {}

// Member functions
void HumanB::attack(void) {
	std::cout << _name << " attacks with ";
	if (_weaponB && _weaponB->getType() != "")
		std::cout << _weaponB->getType() << "\n";
	else
		std::cout << "their bare fists\n";
}

void HumanB::setWeapon(Weapon& weapon) { _weaponB = &weapon; }
