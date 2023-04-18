/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:54:33 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 12:55:01 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Constructors
Harl::Harl() { }

// Destructor
Harl::~Harl() { }

// Member functions - public

void Harl::complain(std::string level) {
	    void (Harl::*fptr[]) (void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string const levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

	int i = 0;
	while (i < 4)
    {
        if (levels[i] == level)
			break ;
		i++;
    }

	switch (i) {
		case 0:
			(this->*fptr[0])();
		case 1:
			(this->*fptr[1])();
		case 2:
			(this->*fptr[2])();
		case 3:
			(this->*fptr[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n\n";
			break;
	}
}

// Member functions - private
void Harl::debug() {
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n\n";
}
void Harl::info() {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}
void Harl::warning() {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n\n";
}
void Harl::error() {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n\n";
}
