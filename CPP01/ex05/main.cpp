#include "Harl.hpp"

int main()
{
    Harl harl;

	std::cout << "DEBUG : ";
    harl.complain("DEBUG");
    std::cout << "INFO : ";
    harl.complain("INFO");
    std::cout << "WARNING : ";
    harl.complain("WARNING");
    std::cout << "ERROR : ";
    harl.complain("ERROR");
    std::cout << "INVALID MESSAGE : ";
    harl.complain("INVALID MESSAGE");
    std::cout << "EMPTY STRING : ";
    harl.complain("");
    return 0;
}
