#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>
# include <iomanip>

struct ContactData
{
	int _index;
	std::string _name;
	std::string _nickname;
	std::string _lastName;
	std::string _darkestSecret;
	std::string _number;
};

class Contact
{

private:
	ContactData _contact;

public:
	Contact();
	~Contact();
	Contact(ContactData newContact);
	Contact(const Contact& other);
	Contact& operator=(const Contact& other);

	ContactData getContact();

};

#endif