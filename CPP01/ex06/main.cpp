#include "Harl.hpp"

int main(int argc, char **argv) {
    Harl harl;

    if (argc != 2) {
		std::cout << "Required number of argument is 2\n";
        return 1;
    }
    harl.complain(argv[1]);
    return 0;
}
