/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:07:10 by amechain          #+#    #+#             */
/*   Updated: 2023/01/19 15:09:39 by amechain         ###   ########.fr       */
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
		HumanB(std::string name);
		void attack(void);

	private:
		Weapon _weaponB;
		std::string _name;
};


#endif
