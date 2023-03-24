// ./loser_sed "filename" "string_to_replace" "replacement_string"

#include <iostream>
#include <fstream>
#include <string>

int	parser(int ac, char **av)
{
	if (ac != 4 || !*av[1] || *av[1] == ' ' || *av[1] == '\t' || !*av[2]) {
		std::cout << "Please check input parameters" << std::endl ;
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

	// Open & recuperer dans une string le contenu du infile
	if(!infile.is_open()) {
		std::cout << "Please check input file" << std::endl ;
		return (1);
	}
	std::getline(infile, content, '\0');
	infile.close();

	// Formater cette string pour remplacer les s1 par les s2
	size_t	i = 0;

    while ((i = content.find(s1, i)) < content.size()) {
        content.erase(i, s1.size());
        content.insert(i, s2);
        i += s2.size();
    }

	// Copy content into the new file
	std::ofstream outfile(path + ".replace");
	if(!outfile.is_open()) {
		std::cout << "Failed to open output file" << std::endl ;
		return (1);
	}
	outfile << content ;
	outfile.close();

}
