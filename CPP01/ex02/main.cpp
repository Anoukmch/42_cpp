/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:58:43 by amechain          #+#    #+#             */
/*   Updated: 2023/01/15 21:18:17 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string s("HI THIS IS BRAIN");
	std::string *stringPTR = &s;
	std::string& stringREF(s);

	std::cout << "Memory address of the string variable : " << &s << "\n";
	std::cout << "Memory address held by stringPTR : " << stringPTR << "\n"; // Check that
	std::cout << "Memory address held by stringREF : " << &stringREF << "\n"; // Check that

	std::cout << "Value of the string variable : " << s << "\n";
	std::cout << "Value pointed to by stringPTR : " << *stringPTR << "\n";
	std::cout << "Value pointed to by stringREF : " << stringREF << "\n";

	stringPTR = &stringREF
}
