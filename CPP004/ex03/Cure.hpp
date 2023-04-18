/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:13:27 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/07 19:52:44 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public :
		Cure();
		Cure( Cure const & src);
		Cure &operator=( Cure const & src);
		~Cure( void );

		AMateria* clone() const;
		virtual void use(ICharacter& target);


};

#endif
