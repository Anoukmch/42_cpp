/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:43:26 by amechain          #+#    #+#             */
/*   Updated: 2023/04/06 18:57:19 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

# include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap();
		ScavTrap( ScavTrap const & src);
		ScavTrap &operator=( ScavTrap const & src);
		ScavTrap(std::string name);
		~ScavTrap( void );

		void guardGate();
		void attack(const std::string& target);

};

#endif
