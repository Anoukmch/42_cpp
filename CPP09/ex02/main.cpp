/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:55:59 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/15 22:18:46 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** ag)
{
	if (ac != 2)
	{
		std::cout << "Program requires one argument" << std::endl;
		return (1);
	}
	try
	{
	
	}
	catch(std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
}

// Why a stack ? 