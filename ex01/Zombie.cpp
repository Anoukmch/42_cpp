/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:58:58 by amechain          #+#    #+#             */
/*   Updated: 2023/01/15 19:40:03 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name(NULL) {
}

Zombie::Zombie(std::string name) : _name(name) {
}

Zombie::~Zombie() {
	std::cout << _name << " destroyed\n";
}

void Zombie::announce(void) { std::cout << _name << "BraiiiiiiinnnzzzZ...\n"; }

void Zombie::setName(std::string name) { _name = name; }
