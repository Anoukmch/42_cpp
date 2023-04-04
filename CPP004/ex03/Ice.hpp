/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:13:32 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/03 15:41:21 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public :
		Ice();
		Ice( Ice const & src);
		Ice &operator=( Ice const & src);
		~Ice( void );
		
		AMateria* clone() const;

};

#endif
