#include <iostream>
#include <cstdlib>

char *upperCase(char *string){
	int index = 0;

	while(string[index])
	{	
		if(string[index] >= 'a' && string[index] <= 'z')
			string[index] = string[index] - 32;
		index++;
	}
	return string;
}

char *removeSpaces(char *string){
	int start = 0;
	int final = 0;
	int index = 0;
	char *finalString;

	while(string[final])
		final++;
	if(string[final-1] == ' ')
		final--;
	while(string[final] == ' ')
		final--;
	while(string[start] == ' ')
		start++;
	finalString = new char[(final - start) + 1];
	while(start <= final)
		finalString[index++] = string[start++];
	finalString[index] = '\0';
	return finalString;
}

int main(int argc, char *argv[]){
	for(int i = 1; i < argc; i++){	
		std::cout << upperCase(removeSpaces(argv[i]));
		if (i != (argc - 1))
			std::cout << " ";
	}
	return 0;
}
