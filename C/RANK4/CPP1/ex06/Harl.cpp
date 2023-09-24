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
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. ";
	std::cout << "You don’t put enough! If you did I would not have to ";
	std::cout << "ask for it!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "I’ve been coming here for years and you just started ";std::cout << "working here last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*ptr_complain[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int size = 4;
	int i;
	int control = 0;
	for (i = 0; i < (size + 1); i++)
	{
		if (i == (size + 1))
			break ;
		if (levels[i] == level)
		{
			control = 1;
			while(i < size)
			{	
				(this->*ptr_complain[i++])();
				if(i != size)
					std::cout << std::endl;
			}
			break ;
		}
	}
	if(control == 0)
	{	
		std::cout << "[ Probably complaining about insignificant problems ]";
		std::cout << std::endl;
	}
}