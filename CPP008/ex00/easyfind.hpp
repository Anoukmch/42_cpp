/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:41:51 by amechain          #+#    #+#             */
/*   Updated: 2023/06/20 18:05:36 by amechain         ###   ########.fr       */
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
# include <algorithm>


template <typename T>
typename T::iterator easyfind(T const& a, int const i)
{
	typename T::iterator it;

	it = std::find(a.begin(), a.end(), i);
	if (it == a.end())
		throw (std::out_of_range("Fail : occurence was not found"));
	return (it);
}

#endif

