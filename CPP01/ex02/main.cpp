/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:58:43 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 11:34:20 by amechain         ###   ########.fr       */
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
	std::cout << "Memory address held by stringPTR : " << stringPTR << "\n";
	std::cout << "Memory address held by stringREF : " << &stringREF << "\n";
	std::cout << std::endl;
	std::cout << "Value of the string variable : " << s << "\n";
	std::cout << "Value pointed to by stringPTR : " << *stringPTR << "\n";
	std::cout << "Value pointed to by stringREF : " << stringREF << "\n";
}
