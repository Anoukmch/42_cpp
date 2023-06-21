/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:44:48 by amechain          #+#    #+#             */
/*   Updated: 2023/06/21 12:16:48 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

# include <iostream>
# include <iomanip>
# include <string>
# include <vector>
# include <algorithm>
# include <numeric>

class Span
{
	public :
		Span();
		Span(unsigned int N);
		Span( Span const & src);
		Span &operator=( Span const & src);
		~Span( void );

		void addNumber(int const& value);
		int shortestSpan();
		int longestSpan();
		std::vector<int> const& getTable(void) const;

		template <typename T>
		void fillSpan(typename T::iterator range_beg, typename T::iterator range_end)
		{
			unsigned int	dist  = std::abs(std::distance(range_beg, range_end));

			if (_table.size() + dist > _n)
				throw std::logic_error("Error : Span is too small to insert range");
			else
			{
				for (typename T::iterator it = range_beg ; it != range_end ; it++)
					_table.push_back(*it);
			}
		}

	private :
		std::vector<int> _table;
		unsigned int _n;
};

std::ostream &operator<<( std::ostream &flux, Span const& var );

#endif
