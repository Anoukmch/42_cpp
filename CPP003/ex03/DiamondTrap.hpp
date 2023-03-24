/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:36:16 by amechain          #+#    #+#             */
/*   Updated: 2023/03/22 14:16:14 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H

# include <iostream>
#include "ClapTrap.hpp" // try without this call - header dependencies
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

	private :
		std::string _name;

};

#endif

// review the use of the attribute in the .cpp
