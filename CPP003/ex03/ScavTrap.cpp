/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:43:10 by amechain          #+#    #+#             */
/*   Updated: 2023/03/23 16:48:00 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Default Constructor Called." << std::endl;
	_hit = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::ScavTrap( ScavTrap const & src) : ClapTrap() {
	std::cout << "ScavTrap Copy Constructed Called" << std::endl;
	*this = src;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "Named ScavTrap Constructor Called." << std::endl;
	_hit = 100;
	_energy = 50;
	_damage = 20;
}

// Destructors
ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap " << _name << " Destructor Called." << std::endl;
}

// Operator overload
ScavTrap & ScavTrap::operator=( ScavTrap const & src) {
	std::cout << "ScavTrap Copy Assignment Operator Called" << std::endl;
	if ( this != &src ) {
		_name = src._name;
		_hit = src._hit;
		_energy = src._energy;
		_damage = src._damage;
	}
	return ( *this );
}

// Member function
void ScavTrap::attack(const std::string& target) {
	if (_hit == 0) {
		std::cout << "ScavTrap " << _name << " cannot attack anymore because is dead " << std::endl;
		return ;
	}
	if (_energy == 0) {
		std::cout << "ScavTrap " << _name << " cannot attack anymore : needs some energy (Remaining energy points : " << _energy << ")" << std::endl;
		return ;
	}
	_energy -= 1;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage! ";
	std::cout << "Costing 1 energy point (Remaining energy points : " << _energy << ")" << std::endl;
}

void ScavTrap::guardGate() {
	if (_hit == 0)
		std::cout << "ScavTrap " << _name << " cannot Gate keep because dead" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
