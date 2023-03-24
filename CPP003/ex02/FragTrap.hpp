/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:43:26 by amechain          #+#    #+#             */
/*   Updated: 2023/03/20 18:50:46 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Frag_TRAP_H
#define Frag_TRAP_H

# include <iostream>
#include "ClapTrap.hpp" // try without this call

class FragTrap : public ClapTrap
{
	public :
		FragTrap();
		FragTrap( FragTrap const & src);
		FragTrap &operator=( FragTrap const & src);
		FragTrap(std::string name);
		~FragTrap( void );

		void highFivesGuys(void);
		void attack(const std::string& target);

	private :

};

#endif
