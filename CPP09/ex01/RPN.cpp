/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:00:11 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/16 21:46:12 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(std::string expr) {
	isValidExpression(expr);
	_expr = expr;
}

RPN::RPN( RPN const & src) {
	*this = src;
}

// Destructors
RPN::~RPN( void ) {
}

// Operator overload
RPN & RPN::operator=( RPN const & src) {
	if ( this != &src ) {
		_expr = src._expr;
		_stack = src._stack;
	}
	return ( *this );
}

std::stack<int> const& RPN::getStack(void) const{ return _stack; }


bool RPN::isValidExpression(const std::string& input) {
    std::string validChars = "0123456789+-/* ";
    for (size_t i = 0; i < input.length(); ++i) {
        if (validChars.find(input[i]) == std::string::npos)
           throw std::logic_error("Wrong input format");
		else if (std::isdigit(input[i]) && std::isdigit(input[i + 1]))
			 throw std::logic_error("Operands must be digit");
    }
    return true;
}

// FOR TESTING PURPOSE
/* void RPN::printStack(std::stack<int> stk) {
    while (!stk.empty()) {
        std::cout << stk.top() << ' ';
        stk.pop();
    }
    std::cout << std::endl;
} */

void RPN::calculator(void)
{
	// try with std::istringstream iss(_expr);
	// int value
	// iss >> value
	for (unsigned long i = 0 ; i < _expr.size() ; i++) // or iterator ?
	{
		if (_expr[i] == ' ')
			;
 		else if (std::isdigit(_expr[i]))
			_stack.push(_expr[i] - '0');
		else
		{
			if (_stack.size() < 2)
				throw std::logic_error("Wrong input format");

			int result;
			int operand2 = _stack.top(); // how to avoid having 2 integers variable ?
			_stack.pop();
			int operand1 = _stack.top();
			_stack.pop();

			if (_expr[i] == '+')
				result = operand1 + operand2;
			if (_expr[i] == '-')
				result = operand1 - operand2;
			if (_expr[i] == '/')
				result = operand1 / operand2;
			if (_expr[i] == '*')
				result = operand1 * operand2;
			_stack.push(result);
		}
	}
}

std::ostream &operator<<( std::ostream &flux, RPN const& var) {
	flux << "Result of the mathematical expression : " << var.getStack().top();
	return ( flux );
}