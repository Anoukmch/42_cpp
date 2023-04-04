/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:13:27 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/03 17:23:52 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public :
		Cure();
		Cure( Cure const & src);
		Cure &operator=( Cure const & src);
		~Cure( void );

		AMateria* clone() const;

		
		
};

#endif
