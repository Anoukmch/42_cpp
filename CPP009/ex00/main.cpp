/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:55:59 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/23 12:46:56 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char** ag)
{
	if (ac != 2)
	{
		std::cout << "Program requires one file" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange btc;
		btc.parseLine(btc.openFile(ag[1]), '|');
	}
	catch(std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
}
