/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:11:48 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/03/20 13:02:00 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap() : _name("Default name"), _hit(10), _energy(10), _damage(0){
	std::cout << "Default constructor called." << std::endl; 
}

ClapTrap::ClapTrap( ClapTrap const & src) {
	std::cout << "Copy constructed called" << std::endl;
	*this = src;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _damage(0) {
	std::cout << "Named ClapTrap constructed" << std::endl;
}
		
// Destructors
ClapTrap::~ClapTrap( void ) {
	std::cout << "Destructor called." << std::endl;
}

// Operator overload 
ClapTrap & ClapTrap::operator=( ClapTrap const & src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		this->_name = src._name;
		this->_hit = src._hit;
		this->_energy = src._energy;
		this->_damage = src._damage;
	}
	return ( *this );
}

// Member functions

void ClapTrap::attack(const std::string& target) {
	if (_hit == 0)
		std::cout << "ClapTrap" << _name << "cannot attack : no hit points left" << std::endl;
	if (_energy == 0)
		std::cout << "ClapTrap" << _name << "cannot attack : no energy points left" << std::endl;
		return ;
	if (target == _name)
		target = "himself";
	_energy -= 1;
	if (_energy < 0)
		_energy = 0;
	std::cout << "ClapTrap" << _name << target << ", causing" << _damage << "points of damage!" << std::endl;
	std::cout << "Remaining energy points : " << _energy << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	_hit -= amount;
	if (_hit < 0)
		_hit = 0;
	std::cout << "ClapTrap" << _name << "receives " << amount << " damages!" << std::endl;
	std::cout << "Remaining hit points : " << _hit << std::endl; 
	// Attacking and repairing cost 1 energy point each
}
void ClapTrap::beRepaired(unsigned int amount) {
	_hit += amount;
	if (_hit > 10)
		_hit = 10;
	_energy -= 1;
	if (_energy < 0)
		_energy = 0;
	std::cout << "ClapTrap" << _name << "get repaired with" << amount <<" hit points" << std::endl;
	std::cout << "Remaining energy points : " << _energy << std::endl;
	// gets <amount> hit points back.
}

//  ClapTrap can’t do anything if it has no hit points or energy points left