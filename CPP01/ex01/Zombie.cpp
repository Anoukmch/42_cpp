/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:58:58 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 11:23:07 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name() {
}

Zombie::Zombie(std::string name) : _name(name) {
}

Zombie::~Zombie() {
	std::cout << _name << " deleted\n";
}

void Zombie::announce(void) { std::cout << _name << ": BraiiiiiiinnnzzzZ...\n"; }

void Zombie::setName(std::string name) { _name = name; }
