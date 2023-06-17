/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:58:18 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/16 22:36:59 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

# include <iostream>
# include <stack>
#include <sstream>

class PmergeMe
{
	public :
		PmergeMe();
		PmergeMe(int ac, char** ag);
		PmergeMe( PmergeMe const & src);
		PmergeMe &operator=( PmergeMe const & src);
		~PmergeMe( void );

		unsigned int isValidExpression(std::string const & number);
		void printer(void);

	private :
		std::vector<unsigned int> _vector;
};

std::ostream &operator<<( std::ostream &flux, PmergeMe const& var);

#endif
