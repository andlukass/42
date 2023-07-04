#include "Zombie.hpp"

Zombie::Zombie()
{
	return;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	return;
}

std::string Zombie::getName()
{
	return this->_name;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}