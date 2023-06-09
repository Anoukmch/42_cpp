/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:41:51 by amechain          #+#    #+#             */
/*   Updated: 2023/06/07 10:50:43 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_H
#define EASY_FIND_H

# include <iostream>
# include <iomanip>
# include <string>
# include <list>
# include <deque>
# include <vector>

// If you receive a const ref and you need to interates on it
// Then your iterator should also be const 

template <typename T>
typename T::iterator easyfind(T & a, int const i)
{
	typename T::iterator it;

	it = std::find(a.begin(), a.end(), i); // ask GPT for typename
	if (it == a.end())
		throw (std::out_of_range("Fail : occurence was not found"));
	return (it);
}

/* 
	If find works on const iterators (begin and end)
	The return value will be const_int since it returns something
	in the range of const_iterators
*/

#endif


