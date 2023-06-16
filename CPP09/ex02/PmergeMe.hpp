/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:58:18 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/16 19:23:42 by amechain         ###   ########.fr       */
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

		void isValidExpression(std::string const & number);

	private :
		std::vector<int> _vector;
};

#endif
