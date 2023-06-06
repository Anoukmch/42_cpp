/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:41:51 by amechain          #+#    #+#             */
/*   Updated: 2023/06/06 18:48:07 by amechain         ###   ########.fr       */
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

template <typename T>
typename T::const_iterator easyfind(T const& a, int const i)
{
	typename T::const_iterator it;

	it = std::find(a.begin(), a.end(), i); // ask GPT for typename
	if (it == a.end())
		throw (std::out_of_range("Fail : occurence was not found"));
	return (it);
}

#endif


// typename T::iterator easyfind(T &c, int i)
// {
// 	typename T::iterator	it;
// 	it = find(c.begin(), c.end(), i);
// 	if (it == c.end())
// 		throw (NotFoundException());
// 	return (it);
// }

