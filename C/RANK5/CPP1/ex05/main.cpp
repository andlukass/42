#include "Harl.hpp"

int main(void)
{
	Harl	harl;
	std::string	level;

	std::cout << "Type a complaning level!" << std::endl;
	std::cout << "> ";
	std::cin >> level;
	harl.complain(level);
	return (0);
}