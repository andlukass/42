#include <iostream>
#include <string>

int main()
{
	std::string sBrain = "HI THIS IS BRAIN";
	std::string *stringPTR = &sBrain;
	std::string &stringREF = sBrain;

	std::cout << "string adress: " << &sBrain << "\n";
	std::cout << "pointer adress: " << stringPTR << "\n";
	std::cout << "reference adress: " << &stringREF << "\n";

	std::cout << "string value: " << sBrain << "\n";
	std::cout << "pointer value: " << *stringPTR << "\n";
	std::cout << "reference value: " << stringREF << "\n";

}