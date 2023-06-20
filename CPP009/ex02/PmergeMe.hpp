/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:58:18 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/17 20:30:36 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

# include <iostream>
# include <stack>
# include <sstream>
# include <vector>

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
		void sort(void);
		std::vector< std::pair<unsigned int, unsigned int> > create_pairs(void);
		void swap_pairs(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector);
		//void sort_seq(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector);
		bool hasDuplicates(void);
		// Remove this function from class. Object do not need to use them
	private :
		std::vector<unsigned int> _vector;
		int _odd;
};

std::ostream &operator<<( std::ostream &flux, PmergeMe const& var);

#endif
