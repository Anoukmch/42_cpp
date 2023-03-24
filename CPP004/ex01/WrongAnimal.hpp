/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:55:00 by amechain          #+#    #+#             */
/*   Updated: 2023/03/21 17:39:10 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

# include <iostream>

class WrongAnimal
{
	public :
		WrongAnimal();
		WrongAnimal( WrongAnimal const & src);
		WrongAnimal &operator=( WrongAnimal const & src);
		~WrongAnimal( void );

		std::string const &getType(void) const;
		void makeSound() const;

	protected :
		std::string _type;
};

#endif

