/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:02:44 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/03/20 14:20:28 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

# include <iostream>

class ClapTrap
{
	public :
		ClapTrap();
		ClapTrap( ClapTrap const & src);
		ClapTrap &operator=( ClapTrap const & src);
		ClapTrap(std::string name);
		~ClapTrap( void );
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private :
		std::string _name;
		int _hit;
		int _energy;
		int _damage;
};

#endif
