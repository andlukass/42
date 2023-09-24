#include <iostream>
#include "Zombie.hpp"

int main()
{
	int hordeSize = 70;
	
	Zombie *z = zombieHorde(hordeSize, "Jefferson");
	for(int i = 0; i < hordeSize; i++)
		z[i].announce();
	
	delete z;
}