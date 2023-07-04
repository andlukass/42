#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Contact
{
private:
	int index;
	std::string number;
	std::string name;
	std::string lastName;
	std::string nickname;
	std::string darkestSecret;
	
public:
	static int s_index;
	static int s_flag;

	int contactIndex(void);
	std::string contactName(void);
	std::string contactNickname(void);
	std::string contactLastName(void);
	std::string contactNumber(void);
	std::string contactDarkestSecret(void);

	void setContact();

};

#endif
