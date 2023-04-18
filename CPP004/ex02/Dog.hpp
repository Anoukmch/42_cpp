/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:55:00 by amechain          #+#    #+#             */
/*   Updated: 2023/04/07 17:10:49 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public AAnimal
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

