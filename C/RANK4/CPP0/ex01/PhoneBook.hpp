#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	PhoneBook(const PhoneBook &src);
	PhoneBook &operator=(const PhoneBook &rhs);
	~PhoneBook();

	void Add();
	void showInfo(int i);
	int getIndex(int i);
	std::string getName(int i);
	std::string getNickname(int i);
	std::string getLastName(int i);
	std::string getNumber(int i);
	std::string getDarkestSecret(int i);
private:
	Contact contact[8];
		
};

void search(PhoneBook newContact);

#endif
