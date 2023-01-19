#include <iostream>
#include <string.h>

int main() {
	int a = 3;
	int b = 4;
	int* ref = &a;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << a << std::endl;
	ref = &b;
	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << a << std::endl;
}
