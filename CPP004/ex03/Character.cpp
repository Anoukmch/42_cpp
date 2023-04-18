/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:25:03 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/07 20:46:34 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors
Character::Character() : _name("Default name") {
	std::cout << "Character Default constructor called." << std::endl;
	for (int i = 0 ; i < 4 ; i++)
		_materias[i] = NULL;
}

Character::Character( Character const & src) {
	std::cout << "Character Copy constructed called" << std::endl;
	for (int i = 0 ; i < 4 ; i++)
		_materias[i] = NULL;
	*this = src;
}

Character::Character(std::string name) : _name(name) {
	std::cout << "Character Named constructor called." << std::endl;
	for (int i = 0 ; i < 4 ; i++)
		_materias[i] = NULL;
}

// Destructors
Character::~Character( void ) {
	std::cout << "Character Destructor called." << std::endl;
}

// Operator overload
Character & Character::operator=( Character const & src) {
	std::cout << "Character Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		_name = src._name;
		this->free_inventory();
		for (int i = 0 ; i < 4 ; i++)
		{
			if (src._materias[i] != NULL)
				_materias[i] = src._materias[i]->clone();
		}
	}
	return ( *this );
}

// Setters
std::string const & Character::getName() const { return (_name); }

// Member function
void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "Materia doesn't exist" << std::endl;
		return ;
	}
	for (int i = 0 ; i < 4 ; i++)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = m;
			std::cout << _name << " is now equipped with : " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << "No place left on inventory" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Can't unequip, not a valid index " << std::endl;
		return ;
	}
	if (_materias[idx] == NULL)
	{
		std::cout << "Nothing equipped at this index " << std::endl;
		return ;
	}
	std::cout << "Just unequipped " << _materias[idx]->getType() << " from inventory" << std::endl;
	_materias[idx] = NULL;
	return ;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Can't use, not a valid index " << std::endl;
		return ;
	}
	if (_materias[idx] == NULL)
	{
		std::cout << "Nothing to use at this index " << std::endl;
		return ;
	}
	_materias[idx]->use(target);
	_materias[idx] = NULL;
	return ;
}

void	Character::free_inventory(void) {
	for (int i = 0 ; i < 4 ; i++)
	{
		if (_materias[i] != NULL)
		{
			delete _materias[i];
			_materias[i] = NULL;
		}
	}
}
