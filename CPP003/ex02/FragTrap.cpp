/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:43:10 by amechain          #+#    #+#             */
/*   Updated: 2023/03/23 16:48:25 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap Default Constructor Called." << std::endl;
	_hit = 100;
	_energy = 100;
	_damage = 30;
}

FragTrap::FragTrap( FragTrap const & src) : ClapTrap() {
	std::cout << "FragTrap Copy Constructed Called" << std::endl;
	*this = src;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "Named FragTrap Constructor Called." << std::endl;
	_hit = 100;
	_energy = 100;
	_damage = 30;
}

// Destructors
FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap " << _name << " Destructor Called." << std::endl;
}

// Operator overload
FragTrap & FragTrap::operator=( FragTrap const & src) {
	std::cout << "FragTrap Copy Assignment Operator Called" << std::endl;
	if ( this != &src ) {
		_name = src._name;
		_hit = src._hit;
		_energy = src._energy;
		_damage = src._damage;
	}
	return ( *this );
}

// Member function
void FragTrap::attack(const std::string& target) {
	if (_hit == 0) {
		std::cout << "FragTrap " << _name << " cannot attack anymore because is dead " << std::endl;
		return ;
	}
	if (_energy == 0) {
		std::cout << "FragTrap " << _name << " cannot attack anymore : needs some energy (Remaining energy points : " << _energy << ")" << std::endl;
		return ;
	}
	_energy -= 1;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage! ";
	std::cout << "Costing 1 energy point (Remaining energy points : " << _energy << ")" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (_hit == 0)
		std::cout << "FragTrap " << _name << "'s ghosts would like to high five'" << std::endl;
	else
		std::cout << "FragTrap " << _name << " kindly requests a high five.. :) " << std::endl;
}
