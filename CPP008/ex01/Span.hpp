/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:44:48 by amechain          #+#    #+#             */
/*   Updated: 2023/06/20 18:55:56 by amechain         ###   ########.fr       */
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
		void fillSpan(std::vector<int>::iterator range_beg, std::vector<int>::iterator range_end);
		std::vector<int> const& getTable(void) const;

	private :
		std::vector<int> _table;
		unsigned int _n;
};

std::ostream &operator<<( std::ostream &flux, Span const& var );

#endif
