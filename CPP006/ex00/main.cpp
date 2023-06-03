/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:23:23 by amechain          #+#    #+#             */
/*   Updated: 2023/06/03 16:31:14 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int	main(int ac, char **ag)
{
	if (ac != 2 || !ag[1][0])
	{
		std::cout << "Program requires one argument" << std::endl;
		return (1);
	}
	try
	{
		ScalarConverter::convert(ag[1]);
		ScalarConverter::printer();
	}
	catch(std::exception const& e)
	{
		std::cout << e.what() << " : Invalid input !" << std::endl;
	}

}
