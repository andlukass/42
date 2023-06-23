#include "phoneBook.hpp"

int addNewContact(PhoneBook newContact,int i)
{
	newContact.Add(i);
	std::cout << "index do contato criado: " << newContact.contact[i].index 
	<< std::endl;

	std::cout << "nome do contato criado: " << newContact.contact[i].name
	<< " " << newContact.contact[i].nickname << " "
	<< newContact.contact[i].lastName
	<< std::endl;

	std::cout << "numero do contato criado: " << newContact.contact[i].number 
	<< std::endl;
	
	std::cout << "segredo do contato criado: " << newContact.contact[i].darkestSecret 
	<< std::endl;
	return 0;
}


int main()
{
	PhoneBook newContact;
	//std::cout << newContact.contact[0].name << std::endl;
	addNewContact(newContact , 0);
	
	//search(newContact);
	
	
	//std::cout << std::setw(10) << std::setfill(' ') << "kkk" << std::endl;


}
