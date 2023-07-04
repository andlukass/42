#include "Contact.hpp"

int Contact::s_index = 0;
int Contact::s_flag = 0;

int Contact::contactIndex(void){
	return this->index;
}

std::string Contact::contactName(void){
	return this->name;
}

std::string Contact::contactNickname(void){
	return this->nickname;
}

std::string Contact::contactLastName(void){
	return this->lastName;
}

std::string Contact::contactNumber(void){
	return this->number;
}

std::string Contact::contactDarkestSecret(void){
	return this->darkestSecret;
}

void Contact::setContact()
{
	int i = Contact::s_index;
	
	int index = i + 1;
	std::string number;
	std::string name;
	std::string lastName;
	std::string nickname;
	std::string darkestSecret;

	std::cout << "Write the contact name:" << std::endl;
	std::cout << "> ";
	while(name.size() == 0)
	{	
		std::getline(std::cin, name);
		if(name.size() == 0)
		{	
			std::cout << "Should not be blank!" << std::endl;
			std::cout << "> ";
		}
	}
	std::cout << std::endl;

	std::cout << "Write the contact last name:" << std::endl;
	std::cout << "> ";
	while(lastName.size() == 0)
	{	
		std::getline(std::cin, lastName);
		if(lastName.size() == 0)
		{	
			std::cout << "Should not be blank!" << std::endl;
			std::cout << "> ";
		}
	}
	std::cout << std::endl;

	std::cout << "Write the contact nickname:" << std::endl;
	std::cout << "> ";
	while(nickname.size() == 0)
	{	
		std::getline(std::cin, nickname);
		if(nickname.size() == 0)
		{	
			std::cout << "Should not be blank!" << std::endl;
			std::cout << "> ";
		}
	}
	std::cout << std::endl;

	std::cout << "Write the contact number:" << std::endl;
	std::cout << "> ";
	while(number.size() == 0)
	{	
		std::getline(std::cin, number);
		if(number.size() == 0)
		{	
			std::cout << "Should not be blank!" << std::endl;
			std::cout << "> ";
		}
	}
	std::cout << std::endl;

	std::cout << "Write the contact darkest secret:" << std::endl;
	std::cout << "> ";
	while(darkestSecret.size() == 0)
	{	
		std::getline(std::cin, darkestSecret);
		if(darkestSecret.size() == 0)
		{	
			std::cout << "Should not be blank!" << std::endl;
			std::cout << "> ";
		}
	}
	std::cout << std::endl;
	std::cout << "new contact added :)" << std::endl;
	std::cout << std::endl;

	if(Contact::s_index < 7)
		Contact::s_index++;
	else
	{	
		Contact::s_flag = 1;
		Contact::s_index = 0;
	}
}
