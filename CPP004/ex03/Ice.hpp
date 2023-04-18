/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:13:32 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/07 19:52:41 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public :
		Ice();
		Ice( Ice const & src);
		Ice &operator=( Ice const & src);
		~Ice( void );

		AMateria* clone() const;
		virtual void use(ICharacter& target);

};

#endif
