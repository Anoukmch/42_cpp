/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:55:00 by amechain          #+#    #+#             */
/*   Updated: 2023/04/07 17:10:45 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public AAnimal
{
	public :
		Cat();
		Cat( Cat const & src);
		Cat &operator=( Cat const & src);
		virtual ~Cat();

		virtual void makeSound() const;
		void setIdea(int i, std::string const& idea);
		std::string const& getIdea(int index) const;

		private :
			Brain *	_brain;
};

#endif

