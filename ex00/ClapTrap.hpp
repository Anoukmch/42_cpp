/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:02:44 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/03/20 12:59:00 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H

# include <iostream>

class ClapTrap
{
	// ADD COPY CONSTRUCTOR AND OPERATOR OVERLOAD
	public :
		ClapTrap();
		ClapTrap( ClapTrap const & src);
		ClapTrap &operator=( ClapTrap const & src) const;
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
}