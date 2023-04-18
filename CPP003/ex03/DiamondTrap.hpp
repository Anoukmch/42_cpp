/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:36:16 by amechain          #+#    #+#             */
/*   Updated: 2023/04/12 13:21:19 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H

# include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public :
		DiamondTrap();
		DiamondTrap( DiamondTrap const & src);
		DiamondTrap &operator=( DiamondTrap const & src);
		~DiamondTrap( void );
		DiamondTrap(std::string name);

		using	ScavTrap::attack;
		void whoAmI();
		void test();

	private :
		std::string _name;

};

#endif

