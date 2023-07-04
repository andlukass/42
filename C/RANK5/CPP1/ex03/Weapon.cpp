#include "Weapon.hpp"

Weapon::Weapon()
{
	return;
}

Weapon::~Weapon()
{
	return;
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon& Weapon::operator=(const Weapon& other)
{
	if(this == &other)
		return *this;
	
	_type = other._type;
	return *this;

}

std::string Weapon::getType()
{
	return this->_type;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}