#include "PhoneBook.hpp"

static std::string truncateString(const std::string& str) {
    if (str.length() <= 10) {
        return str;
    } else {
        return str.substr(0, 10 - 1) + ".";
    }
}

static void printDiv()
{
	std::cout << "+" << std::setw(44) << std::setfill('-') << "+";
	std::cout << std::endl;
}

static void printTitle()
{
	printDiv();
	std::cout << "|     index|      name|  nickname| last name|";
	std::cout << std::endl;
	printDiv();
}

static void printLine(PhoneBook newContact)
{
	std::cout << "|";
	std::cout << std::setw(10) << std::setfill(' ') 
	<< newContact.contact[0].index << "|";

	std::cout << std::setw(10) << std::setfill(' ') 
	<< truncateString(newContact.contact[0].name) << "|";

	std::cout << std::setw(10) << std::setfill(' ') 
	<< truncateString(newContact.contact[0].nickname) << "|";

	std::cout << std::setw(10) << std::setfill(' ') 
	<< truncateString(newContact.contact[0].lastName) << "|";
	std::cout << std::endl;
	printDiv();
}

void search(PhoneBook newContact)
{
	printTitle();
	for(int i = 0; i < 4; i++)
		printLine(newContact);
}
