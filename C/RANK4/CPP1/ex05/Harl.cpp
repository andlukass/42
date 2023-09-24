#include "Harl.hpp"

Harl::Harl(void)
{
	return;
}

Harl::~Harl(void)
{
	return;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my ";
	std::cout << "XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. ";
	std::cout << "You don’t put enough! If you did I would not have to ";
	std::cout << "ask for it!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "I’ve been coming here for years and you just started ";std::cout << "working here last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*ptr_complain[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i;
	for (i = 0; i < 5; i++)
	{
		if (i == 5)
			break ;
		if (levels[i] == level)
		{
			(this->*ptr_complain[i])();
			break ;
		}
	}
	if(i == 5)
		std::cout << "Complaining not found!" << std::endl;
}