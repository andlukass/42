#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB{
private:
	std::string _name;
	Weapon *_weapon;

public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon &weapon);

	std::string getName();
	void setName(std::string name);
	std::string getWeapon();
	void setWeapon(Weapon &weapon);
	void attack();

};

#endif