/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:55:59 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/17 21:21:54 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** ag)
{
	if (ac < 3)
	{
		std::cout << "Program requires at least 2 arguments" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe pmergeme(ac, ag);
		pmergeme.sort();

    }
	catch(std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
}

// Does the two algo has to be the same for each container or do it differently ?
// "It is strongly advised to implement your algorithm for each container
//and thus to avoid using a generic function" --> Why ? It's just a duplicate piece of code, it doesnt make sense

// Compare algo the Felix's one

// if time, handle "2 3 4" (multiple digits in one argc & only one arg but with multiple digit
