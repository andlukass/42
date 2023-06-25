#include "PhoneBook.hpp"

int main()
{
	ContactData teste;
	teste._name = "marcos";
	teste._nickname = " goleiro ";
	teste._lastName = "do parmera";
	PhoneBook phoneBook;

	phoneBook.Add(teste, 0);
	std::cout << phoneBook.Search(0)._name << std::endl;
}
