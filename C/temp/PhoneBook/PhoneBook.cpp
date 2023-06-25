#include "PhoneBook.hpp"

ContactData PhoneBook::Search(int i)
{
	return this->_contacts[i].getContact();
}

void PhoneBook::Add(ContactData newContact, int i)
{
	Contact contact(newContact);
	this->_contacts[i] = contact;
}

PhoneBook::PhoneBook()
{
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

PhoneBook::PhoneBook(const PhoneBook& other)
{
	return ;
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other)
{
	if (this == &other)
		return *this;

	for (int i = 0; i < _arrSize; i++)
		_contacts[i] = other._contacts[i];

	return *this;
}
