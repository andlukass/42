#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
public:
	static int s_index;
	int index;
	std::string number;
	std::string name;
	std::string lastName;
	std::string nickname;
	std::string darkestSecret;
};

int Contact::s_index = 1;

class PhoneBook
{
public:
	Contact *contact;

	void Add(int i)
	{
		contact[i].index = Contact::s_index;

		std::cout << "Write the contact name:" << std::endl;
		std::cin >> contact[i].name;
		std::cout << std::endl;

		std::cout << "Write the contact last name:" << std::endl;
		std::cin >> contact[i].lastName;
		std::cout << std::endl;

		std::cout << "Write the contact nickname:" << std::endl;
		std::cin >> contact[i].nickname;
		std::cout << std::endl;

		std::cout << "Write the contact number:" << std::endl;
		std::cin >> contact[i].number;
		std::cout << std::endl;

		std::cout << "Write the contact darkest secret:" << std::endl;
		std::cin >> contact[i].darkestSecret;
		std::cout << std::endl;
		
		Contact::s_index++;
	}

};

void search(PhoneBook newContact);

#endif
