#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];
	int counter = 1;
	for(int i = 0; i < N; i++)
		zombies[i].setName(name + std::to_string(counter++));
	return zombies;
}