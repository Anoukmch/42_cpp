/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:55:59 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/23 14:18:44 by amechain         ###   ########.fr       */
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
		std::cout << "Program requires one and only one argument" << std::endl;
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
