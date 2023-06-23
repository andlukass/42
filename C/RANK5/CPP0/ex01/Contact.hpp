#ifndef CONTACT_HPP
# define CONTACT_HPP

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

#endif
