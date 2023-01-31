int main ()
{
  std::string name;

  std::cout << "Please, enter your full name: ";
  std::getline (std::cin,name);
  std::cout << "Hello, " << name << "!\n";


	// OR 

	cout<<"do you want to do it again ? Y/N ";
	cin>>choice;

	return 0;
}

#include <iostream>

#include <iomanip>

int main () {

	std::cout << std::setw(5);

	std::cout <<123456<< std::endl;

	std::cout <<42<< std::endl;

return 0;

}