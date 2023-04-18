/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:41:50 by amechain          #+#    #+#             */
/*   Updated: 2023/04/07 21:13:28 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource() : _inventory(0) {
	std::cout << "Materia Default constructor called." << std::endl;
}

MateriaSource::MateriaSource( MateriaSource const & src) {
	std::cout << "MateriaSource Copy constructed called" << std::endl;
	*this = src;
}

// Destructors
MateriaSource::~MateriaSource( void ) {
	std::cout << "MateriaSource Destructor called." << std::endl;
	for (int i = 0 ; i < _inventory ; i++)
		delete _array[i];
}

// Operator overload
MateriaSource & MateriaSource::operator=( MateriaSource const & src) {
	std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if ( this != &src ) {
		for (int i = 0 ; i < _inventory ; i++)
			_array[i] = src._array[i]->clone();
	}
	return ( *this );
}

// Member function
void	MateriaSource::learnMateria(AMateria * obj) {
	if (_inventory >= 4)
	{
		std::cout << "Inventory is full" << std::endl;
		return ;
	}
	_array[_inventory] = obj;
	_inventory++;
	std::cout << "Inventory just add : " << obj->getType() << std::endl;

}

AMateria * MateriaSource::createMateria(std::string const & type) {
	for (int i = _inventory - 1 ; i >= 0 ; i--)
	{
		if (_array[i]->getType() == type) {
			std::cout << "Here is a copy of : " << type << std::endl;
			return (_array[i]->clone());
		}
	}
	std::cout << "Unknown materia type " << std::endl;
	return (NULL);
}
