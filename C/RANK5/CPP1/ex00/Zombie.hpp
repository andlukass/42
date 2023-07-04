#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>
# include <iostream>

class Zombie
{
private:
	std::string _name;

public:
	Zombie();
	~Zombie();
	Zombie(const Zombie& other);
	Zombie& operator=(const Zombie& other);

	Zombie(std::string name);

	void announce(void);
};

	void randomChump(std::string name);
	Zombie *newZombie(std::string name);

#endif