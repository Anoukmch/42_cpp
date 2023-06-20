/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:55:59 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/16 12:30:30 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main(int ac, char** ag)
{	
	if (ac != 2)
	{
		std::cout << "Program requires one argument" << std::endl;
		return (1);
	}
	try
	{
		RPN rpn(ag[1]);
		rpn.calculator();
		std::cout << rpn << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
}

// Why a stack ? 