/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:00:11 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/23 14:39:24 by amechain         ###   ########.fr       */
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
			 throw std::logic_error("Operands must be one digit");
    }
    return true;
}

void RPN::printStack(std::stack<int> stack, char c) {
	std::cout << "Oper. :\t" << c << "\t| Stack :\t";
    while (!stack.empty()) {
    	std::cout << stack.top() << ' ';
        stack.pop();
    }
    std::cout << std::endl;
}

void RPN::calculator(void)
{
	for (unsigned long i = 0 ; i < _expr.size() ; i++)
	{
		if (_expr[i] == ' ')
			;
 		else if (std::isdigit(_expr[i]))
		{
			_stack.push(_expr[i] - '0');
			printStack(_stack, _expr[i]);
		}
		else
		{
			if (_stack.size() < 2)
				throw std::logic_error("Wrong input format");

			int result;
			int operand2 = _stack.top();
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
			printStack(_stack, _expr[i]);
		}
	}
	if (_stack.size() != 1)
		throw std::logic_error("Wrong input format");
}

std::ostream &operator<<( std::ostream &flux, RPN const& var) {
	flux << "Result of the mathematical expression : " << var.getStack().top();
	return ( flux );
}
