/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:20:20 by amechain          #+#    #+#             */
/*   Updated: 2023/01/30 15:44:41 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructors

Weapon::Weapon() {}
Weapon::Weapon(std::string type) : _type(type) {}

// Destructor
Weapon::~Weapon() {}

// Member functions
const std::string& Weapon::getType() const { return _type; }
void Weapon::setType(std::string const& type) { _type = type; }

