#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
	}
	for (int i = 1; av[i]; i++) {
		std::string s(av[i]);
		for (std::string::iterator it = s.begin(); it != s.end(); it++)
			*it = std::toupper(*it);
		std::cout << s;
	}
	std::cout << std::endl;
	return (0);
}
