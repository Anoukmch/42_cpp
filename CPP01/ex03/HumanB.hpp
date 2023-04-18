/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:07:10 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 11:49:09 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB();
		HumanB(std::string const& name);
		~HumanB();
		void attack();
		void setWeapon(Weapon& weapon);

	private:
		Weapon* _weaponB;
		std::string _name;
};

#endif
