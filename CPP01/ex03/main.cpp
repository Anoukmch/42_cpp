#include <iostream>
#include <string.h>

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("tranchant"); // Weapon
		HumanA bob("Bob", club); // Bob constructor (function) create a copy of Weapon
		bob.attack();
		club.setType("some other type of club"); // To automatically update "bob", we need to have a reference towards "club"
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
