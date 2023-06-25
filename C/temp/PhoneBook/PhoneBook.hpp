#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact _contacts[8];

public:
	PhoneBook();
	~PhoneBook();
	PhoneBook(const PhoneBook& other);
	PhoneBook& operator=(const PhoneBook& other);

	void Add(ContactData newContact, int i);
	ContactData Search(int i);

};

	static int _arrSize = 8;

#endif