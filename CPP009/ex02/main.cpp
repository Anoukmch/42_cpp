/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:55:59 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/23 14:45:25 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** ag)
{
	if (ac < 3)
	{
		std::cout << "Program requires at least 2 arguments in a sequence" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe pmergeme(ac, ag);
		pmergeme.sort_menu();

    }
	catch(std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
}
