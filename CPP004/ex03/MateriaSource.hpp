/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:41:47 by amechain          #+#    #+#             */
/*   Updated: 2023/04/07 20:18:24 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public :
		MateriaSource();
		MateriaSource( MateriaSource const & src);
		MateriaSource &operator=( MateriaSource const & src);
		virtual ~MateriaSource( void );

		void	learnMateria(AMateria * obj);
		AMateria * createMateria(std::string const & type);

	private :
		AMateria	*_array[4];
		int			_inventory;

};

#endif
