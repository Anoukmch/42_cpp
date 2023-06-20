/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:44:48 by amechain          #+#    #+#             */
/*   Updated: 2023/06/20 17:51:32 by amechain         ###   ########.fr       */
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

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T,C> // Try public std::vector<int> to see if inheritance possible
{
	public :

		typedef typename C::iterator iterator;
		typedef typename C::const_iterator const_iterator;
		typedef typename C::reverse_iterator reverse_iterator;
		typedef typename C::const_reverse_iterator const_reverse_iterator;

		MutantStack():std::stack<T>() {};
		MutantStack( MutantStack const & src):std::stack<T>(src) {*this = src;}
		MutantStack &operator=( MutantStack const & src)
		{
			if (this != &src)
				this->c = src.c;
			return (*this);
		}
		~MutantStack( void ) {};

		iterator begin() {return (this->c.begin());};
		iterator end() {return (this->c.end());};

		reverse_iterator rbegin() {return (this->c.rbegin());};
		reverse_iterator rend() {return (this->c.rend());};

		const_iterator cbegin() {return (this->c.cbegin());};
		const_iterator cend() {return (this->c.cend());};

		const_reverse_iterator crbegin() {return (this->c.crbegin());};
		const_reverse_iterator crend() {return (this->c.crend());};
};

#endif
