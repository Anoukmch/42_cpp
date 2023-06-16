/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:55:59 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/16 17:54:26 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** ag)
{,
	if (ac < 3)
	{
		std::cout << "Program requires at least 2 arguments" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe pmergeme(ac, ag);
	}
	catch(std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
}
