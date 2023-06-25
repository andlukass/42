#include "Contact.hpp"

ContactData Contact::getContact()
{
	return this->_contact;
}

Contact::Contact(ContactData newContact)
{
	this->_contact = newContact;
	return ;
}

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

Contact::Contact(const Contact& other)
{
	return ;
}

Contact& Contact::operator=(const Contact& other)
{
	if (this == &other)
		return *this;

	_contact = other._contact;
	return *this;
}

