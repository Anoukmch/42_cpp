/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:37:22 by amechain          #+#    #+#             */
/*   Updated: 2023/04/12 14:07:02 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap() : ScavTrap(), _name("Default DiamondTrap name")
{
	std::cout << "DiamondTrap Default Constructor Called." << std::endl;
	std::cout << "THE ONE " << ScavTrap::getHIT() << std::endl;
	_hit = FragTrap::_hit;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src) : ScavTrap(src) {
	std::cout << "DiamondTrap Copy Constructed Called" << std::endl;
	*this = src;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), _name(name) {
	_hit = FragTrap::_hit;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
}

// Destructors
DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap " << _name << " Destructor Called." << std::endl;
}

// Operator overload
DiamondTrap & DiamondTrap::operator=( DiamondTrap const & src) {
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		_name = src._name;
		_hit = src._hit;
		_energy = src._energy;
		_damage = src._damage;
	}
	return ( *this );
}

void DiamondTrap::test() {
	std::cout << "name : " << _name << std::endl;
	std::cout << "hit : " << _hit << std::endl;
	std::cout << "energy : " << _energy << std::endl;
	std::cout << "damage : " << _damage << std::endl;
}

// Member functions
void DiamondTrap::whoAmI() {
	std::cout << "I'm non binary so you can call me by my ClapTrap name : " << ClapTrap::_name << ", or my DiamondTrap name : " << _name << std::endl;
}
