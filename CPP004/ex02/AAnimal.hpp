/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:55:00 by amechain          #+#    #+#             */
/*   Updated: 2023/03/23 17:57:54 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
#define AANIMAL_H

# include <iostream>

class AAnimal
{
	public :
		AAnimal();
		AAnimal( AAnimal const & src);
		AAnimal &operator=( AAnimal const & src);
		virtual ~AAnimal( void );

		std::string const &getType(void) const;
		virtual void makeSound() const = 0;

	protected :
		std::string _type;
};

#endif

