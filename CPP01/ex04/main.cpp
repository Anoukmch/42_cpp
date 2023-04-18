/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:05:58 by amechain          #+#    #+#             */
/*   Updated: 2023/04/05 13:01:00 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	parser(int ac, char **av)
{
	if (ac != 4 || !*av[1] || *av[1] == ' ' || *av[1] == '\t' || !*av[2]) {
		std::cout << "Please specify a file name and two string patterns" << std::endl ;
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (parser(ac, av)) { return 1; }
	std::string path(av[1]);
	std::string content;
	std::string s1(av[2]);
	std::string s2(av[3]);
	std::ifstream infile(path);

	// Open the infile & get the content in a string
	if(!infile.is_open()) {
		std::cout << "Please check input file" << std::endl ;
		return (1);
	}
	std::getline(infile, content, '\0');
	infile.close();

	// Format this string to replace s1 by s2
	size_t	i = 0;

    while ((i = content.find(s1, i)) < content.size()) {
        content.erase(i, s1.size());
        content.insert(i, s2);
        i += s2.size();
    }

	// Copy content into the newly created outfile
	std::ofstream outfile(path + ".replace");
	if(!outfile.is_open()) {
		std::cout << "Failed to open output file" << std::endl ;
		return (1);
	}
	outfile << content ;
	outfile.close();
	std::cout << std::endl;
	system("leaks ex04");
}
