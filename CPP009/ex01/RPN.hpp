/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:58:18 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/21 15:47:49 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

# include <iostream>
# include <stack>

class RPN
{
	public :
		RPN();
		RPN(std::string expr);
		RPN( RPN const & src);
		RPN &operator=( RPN const & src);
		~RPN( void );

		void calculator(void);
		bool isValidExpression(const std::string& input);
		void printStack(std::stack<int> stack, char c);
		std::stack<int> const& getStack(void) const;

	private :
		std::stack<int> _stack;
		std::string _expr;
};

std::ostream &operator<<( std::ostream &flux, RPN const& var);

#endif
