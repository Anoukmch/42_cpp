/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:13:10 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/04/03 18:00:18 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

# include <iostream>

class AMateria
{
	public :
		AMateria();
		AMateria( AMateria const & src);
		AMateria(std::string const & type);
		AMateria &operator=( AMateria const & src);
		virtual ~AMateria( void );

		std::string const & getType() const; //Returns the materia type
		//virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected :
		std::string _type;
};

#endif
