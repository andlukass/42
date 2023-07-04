#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::Zombie()
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << "activaded, killing zombie: " << _name << std::endl;
}

Zombie::Zombie(const Zombie& other)
{
	return ;
}

Zombie& Zombie::operator=(const Zombie& other)
{
	if (this == &other)
		return *this;

	_name = other._name;
	return *this;
}
