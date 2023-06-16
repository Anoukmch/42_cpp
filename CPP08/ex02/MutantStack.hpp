/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:44:48 by amechain          #+#    #+#             */
/*   Updated: 2023/06/08 18:28:34 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

# include <iostream>
# include <iomanip>
# include <string>
# include <stack>

// Typename ?
// Try to create a class template with two arg and to send only one

template <typename T, typename C> // Template < typename T, typename C = std::deque<T> > by default
class MutantStack : public std::stack<T,C> // Try public std::vector<int>
{
	// Need to define iterator to be able to create :
	std::stack<int>::iterator test;

	iterator begin();
};

// Faire des recherches : typedef in a class

#endif
