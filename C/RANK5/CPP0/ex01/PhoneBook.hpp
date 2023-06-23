#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
public:
	Contact contact[8];

	void Add(int i)
	{
		contact[i].index = Contact::s_index;

		std::cout << "Write the contact name:" << std::endl;
		std::cout << ">";
		std::cin >> contact[i].name;
		std::cout << std::endl;

		std::cout << "Write the contact last name:" << std::endl;
		std::cout << ">";
		std::cin >> contact[i].lastName;
		std::cout << std::endl;

		std::cout << "Write the contact nickname:" << std::endl;
		std::cout << ">";
		std::cin >> contact[i].nickname;
		std::cout << std::endl;

		std::cout << "Write the contact number:" << std::endl;
		std::cout << ">";
		std::cin >> contact[i].number;
		std::cout << std::endl;

		std::cout << "Write the contact darkest secret:" << std::endl;
		std::cout << ">";
		std::cin >> contact[i].darkestSecret;
		std::cout << std::endl;
		
		Contact::s_index++;
	}

};

void search(PhoneBook newContact);

#endif
