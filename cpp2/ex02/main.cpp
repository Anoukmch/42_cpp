#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a(3);
	Fixed const b(2);
	Fixed res;

	res = a + b;

	std::cout << res << std::endl;
}