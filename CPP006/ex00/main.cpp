/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:23:23 by amechain          #+#    #+#             */
/*   Updated: 2023/05/23 18:38:36 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	1. Detect the type of the literal passed as parameter
	2. Conversion from string to 4 data types
	4. Display

	argv[1] --> ScalarConverter::convert(std::string const& input)


*/

#include "Scalar.hpp"

int	main(int ac, char **ag)
{
	ScalarConverter obj;
	if (ac != 2 || !ag[1][0])
	{
		std::cout << "Program requires one argument" << std::endl;
		return (1);
	}
	try
	{
		obj.convert(ag[1]);
		std::cout << obj;
	}
	catch(std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

}
