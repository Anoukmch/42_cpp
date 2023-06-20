/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:58:18 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/16 12:36:34 by anoukmechai      ###   ########.fr       */
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
		//void printStack(std::stack<int> stk);
		std::stack<int> const& getStack(void) const;

	private :
		std::stack<int> _stack;
		std::string _expr;
};

std::ostream &operator<<( std::ostream &flux, RPN const& var);

#endif