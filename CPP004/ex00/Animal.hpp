/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:55:00 by amechain          #+#    #+#             */
/*   Updated: 2023/03/22 16:42:46 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

# include <iostream>

class Animal
{
	public :
		Animal();
		Animal( Animal const & src);
		Animal &operator=( Animal const & src);
		virtual ~Animal( void );

		std::string const &getType(void) const;
		virtual void makeSound() const;

	protected :
		std::string _type;
};

#endif

