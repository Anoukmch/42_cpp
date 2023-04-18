/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:13:10 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/07 20:31:53 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public :
		AMateria();
		AMateria( AMateria const & src);
		AMateria(std::string const & type);
		AMateria &operator=( AMateria const & src);
		virtual ~AMateria( void );

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected :
		std::string _type;
};

#endif
