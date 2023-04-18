/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:54:25 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 13:01:07 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
    Harl harl;

    if (argc != 2) {
		std::cout << "Required number of argument is 2. Try DEBUG, INFO, WARNING or ERROR.\n";
        return 1;
    }
    harl.complain(argv[1]);
    std::cout << std::endl;
    system("leaks harlFilter");
    return 0;
}
