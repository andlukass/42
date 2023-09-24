#include "PhoneBook.hpp"

std::string truncateString(const std::string& str)
{
	if (str.length() <= 10)
		return str;
	else
		return str.substr(0, 10 - 1) + ".";
}

void printDiv()
{
	std::cout << "+" << std::setw(44) << std::setfill('-') << "+\n";
}

void printTitle()
{
	printDiv();
	std::cout << "|     index|      name|  nickname| last name|\n";
	printDiv();
}

static void printLine(PhoneBook newContact, int i)
{
	if(i == 0 && newContact.getName(0).size())
		printTitle();

	while(newContact.getName(i).size() > 0)
	{
		std::cout << "|";
		std::cout << std::setw(10) << std::setfill(' ') 
		<< newContact.getIndex(i) << "|";

		std::cout << std::setw(10) << std::setfill(' ') 
		<< truncateString(newContact.getName(i)) << "|";

		std::cout << std::setw(10) << std::setfill(' ') 
		<< truncateString(newContact.getNickname(i)) << "|";

		std::cout << std::setw(10) << std::setfill(' ') 
		<< truncateString(newContact.getLastName(i)) << "|";
		std::cout << std::endl;
		printDiv();
		i++;
		if(i == 8)
			break;
	}
}

void search(PhoneBook newContact)
{
	int i = 0;
	std::string index;
	std::string toCompare = "12345678";

	if(newContact.getName(0).size() == 0)
		std::cout << "no contacts to show, try 'ADD' command.\n";
	else
	{
		printLine(newContact, i);
		std::cout << "choose the contact index to see more details\n> ";
		std::getline(std::cin, index);
		std::cout << std::endl;
		if(toCompare.find(index) != std::string::npos)
			newContact.showInfo(std::atoi((index.c_str()) - 1));
	}
}
