/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:06:42 by amechain          #+#    #+#             */
/*   Updated: 2023/01/19 15:09:16 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon weapon);
		void attack(void);

	private:
		Weapon _weaponA;
		std::string _name;

};


#endif
