/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:58:18 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/21 19:48:36 by amechain         ###   ########.fr       */
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
		void create_pairs(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector);
		void swap_pairs(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector);
		void sort_seq(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector);
		bool hasDuplicates(void);
		void make_main_and_pend(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector);
		// Remove this function from class. Object do not need to use them

		template <typename T>
		static void	swap(T &a, T &b)
		{
			T buf;

			buf = a;
			a = b;
			b = buf;
		}

	private :
		std::vector<unsigned int> _vector;
		int _odd;
};

std::ostream &operator<<( std::ostream &flux, PmergeMe const& var);

#endif
