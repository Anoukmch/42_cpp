/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:44:48 by amechain          #+#    #+#             */
/*   Updated: 2023/06/07 18:27:06 by anoukmechai      ###   ########.fr       */
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
	
	private : 
		std::vector<int> _table;
		unsigned int _n;
};


#endif
