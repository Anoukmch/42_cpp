/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:55:00 by amechain          #+#    #+#             */
/*   Updated: 2023/04/07 16:45:18 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public Animal
{
	public :
		Dog();
		Dog( Dog const & src);
		Dog &operator=( Dog const & src);
		virtual ~Dog();

		virtual void makeSound() const;
		void setIdea(int i, std::string const& idea);
		std::string const& getIdea(int index) const;

		private :
			Brain *	_brain;
};

#endif

