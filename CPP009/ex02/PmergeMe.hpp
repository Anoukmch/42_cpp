/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:58:18 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/23 15:48:51 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

# include <iostream>
# include <stack>
# include <sstream>
# include <vector>
# include <deque>
# include <ctime>

class PmergeMe
{
	public :
		PmergeMe(int ac, char** ag);
		PmergeMe( PmergeMe const & src);
		PmergeMe &operator=( PmergeMe const & src);
		~PmergeMe( void );

		void sort_menu(void);

		void sort_vec(void);
		void create_pairs(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector);
		void swap_pairs(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector);
		void sort_seq(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector);
		void make_main_and_pend(std::vector< std::pair<unsigned int, unsigned int> > & pairsVector, std::vector<unsigned int> & pend);
		void create_jac_seq(std::vector<unsigned int> & pend);
		void create_full_insert_sec(std::vector<unsigned int> & pend, std::vector<unsigned int> & indexSequence);
		void insert_pend(std::vector<unsigned int> & pend, std::vector<unsigned int> & indexSequence);
		int  bisect_vec(unsigned int x );

		void sort_deq(void);
		void create_pairs(std::deque< std::pair<unsigned int, unsigned int> > & pairsDeque);
		void swap_pairs(std::deque< std::pair<unsigned int, unsigned int> > & pairsDeque);
		void sort_seq(std::deque< std::pair<unsigned int, unsigned int> > & pairsDeque);
		void make_main_and_pend(std::deque< std::pair<unsigned int, unsigned int> > & pairsDeque, std::deque<unsigned int> & pend);
		void create_jac_seq(std::deque<unsigned int> & pend);
		void create_full_insert_sec(std::deque<unsigned int> & pend, std::deque<unsigned int> & indexSequence);
		void insert_pend(std::deque<unsigned int> & pend, std::deque<unsigned int> & indexSequence);
		int  bisect_deq(unsigned int x );

		void timer(std::clock_t vecTime, std::clock_t deqTime);
		void print_vec();
		void print_deq();

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
		std::deque<unsigned int> _deque;
		std::vector<unsigned int> _jacobSeq;
		int _odd;

		PmergeMe();
};

std::ostream &operator<<( std::ostream &flux, PmergeMe const& var);

#endif
