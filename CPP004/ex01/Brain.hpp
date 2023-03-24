/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:10:50 by amechain          #+#    #+#             */
/*   Updated: 2023/03/22 17:35:08 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

# include <iostream>

class Brain
{
	public :
		Brain();
		Brain( Brain const & src);
		Brain &operator=( Brain const & src);
		~Brain( void );

	private :
		std::string ideas[100];
};

#endif
