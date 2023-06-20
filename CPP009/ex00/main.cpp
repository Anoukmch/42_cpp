/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:55:59 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/15 21:56:17 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Je ne comprends pas bien l'ambivalence entre main et classe. 
// Ici je ne sais pas quelles fonctions vont dans la classe ou dans le main.

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