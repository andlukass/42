#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

HumanB::HumanB(std::string name, Weapon &weapon)
{
	this->_name = name;
	this->_weapon = &weapon;
}

std::string HumanB::getName()
{
	return this->_name;
}

void HumanB::setName(std::string name)
{
	this->_name = name;
}

std::string HumanB::getWeapon()
{
	return this->_weapon->getType();
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack()
{
	std::cout << this->_name << " attacks with their "
	<< this->_weapon->getType() << "\n";
}