/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:11:48 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/03/23 16:48:43 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap() : _name("Default name"), _hit(10), _energy(10), _damage(0){
	std::cout << "ClapTrap Default constructor called." << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src) {
	std::cout << "ClapTrap Copy constructed called" << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _damage(0) {
	std::cout << "Named ClapTrap constructor called" << std::endl;
}

// Destructors
ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap Destructor called." << std::endl;
}

// Operator overload
ClapTrap & ClapTrap::operator=( ClapTrap const & src) {
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		_name = src._name;
		_hit = src._hit;
		_energy = src._energy;
		_damage = src._damage;
	}
	return ( *this );
}

// Member functions
void ClapTrap::attack(const std::string& target) {
	if (_hit == 0) {
		std::cout << "ClapTrap " << _name << " cannot attack anymore because is dead " << std::endl;
		return ;
	}
	if (_energy == 0) {
		std::cout << "ClapTrap " << _name << " cannot attack anymore : needs some energy (Remaining energy points : " << _energy << ")" << std::endl;
		return ;
	}
	_energy -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage! ";
	std::cout << "Costing 1 energy point (Remaining energy points : " << _energy << ")" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hit == 0) {
		std::cout << _name << " cannot take damage because is dead" << std::endl;
		return ;
	}
	_hit -= amount;
	if (_hit < 0)
		_hit = 0;
	std::cout  << _name << " receives " << amount << " damages ";
	std::cout << "(Remaining hit points : " << _hit << ")" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy == 0) {
		std::cout << _name << " cannot get repaired anymore : needs some energy (Remaining energy points : " << _energy << ")" << std::endl;
		return ;
	}
	_hit += amount;
	_energy -= 1;
	if (_energy < 0)
		_energy = 0;
	std::cout << _name << " get repaired with " << amount <<" hit points ";
	std::cout << "(Remaining hit points : " << _hit << ") | ";
	std::cout << "Costing 1 energy point (Remaining energy points : " << _energy << ")" << std::endl;
}

//  ClapTrap can’t do anything if it has no hit points or energy points left
// If motivated, try to limit hit points to the maximum
