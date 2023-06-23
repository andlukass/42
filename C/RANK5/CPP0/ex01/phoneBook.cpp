#include "PhoneBook.hpp"


void addNewContact(PhoneBook newContact,int i)
{	
	newContact.Add(i);
	std::cout << "new contact added :)" << std::endl;
	std::cout << std::endl;
}

void waitingRoom(PhoneBook newContact)
{
	std::string command;
	int flag = 0;

	while(1)
	{
		if(!flag)
		{	
			std::cout << "type a command: " << std::endl;
			std::cout << "> ";
			std::cin >> command;
		}
		if(command == "ADD")
			addNewContact(newContact, 0);
		else if(command == "SEARCH")
			search(newContact);
		else if(command == "EXIT")
			std::exit(EXIT_SUCCESS);
		else
			std::cout << "not a valid command" << std::endl;
		flag = 0;
	}
}

int main()
{
	PhoneBook newContact;

	waitingRoom(newContact);
}
