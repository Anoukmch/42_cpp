/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:55:38 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 13:00:35 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

	std::cout << "DEBUG : ";
    harl.complain("DEBUG");
    std::cout << "INFO : ";
    harl.complain("INFO");
    std::cout << "WARNING : ";
    harl.complain("WARNING");
    std::cout << "ERROR : ";
    harl.complain("ERROR");
    std::cout << "INVALID MESSAGE : ";
    harl.complain("INVALID MESSAGE");
    std::cout << "EMPTY STRING : ";
    harl.complain("");
    std::cout << std::endl;
    system("leaks ex05");
    return 0;
}
