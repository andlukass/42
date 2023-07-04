#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->_name = name;
	this->_weapon = &weapon;
}

std::string HumanA::getName()
{
	return this->_name;
}

void HumanA::setName(std::string name)
{
	this->_name = name;
}

std::string HumanA::getWeapon()
{
	return this->_weapon->getType();
}

void HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their "
	<< this->_weapon->getType() << "\n";
}