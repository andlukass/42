#include <iostream>
#include <fstream>
#include <string>

void getFile(std::ifstream &file, std::string &fileContent)
{
	char c;
	while (file.get(c)) {
		fileContent = fileContent + c;
	}
}

void replaceContent(std::string &fileContent,
						std::string toBeReplaced,
							std::string &toReplace)
{
	std::string array[3];
	int pos = 1;

	while(pos != -1)
	{
		pos = fileContent.find(toBeReplaced);
		if(pos != -1)
		{
			array[0] = fileContent.substr(0, pos);
			array[1] = toReplace;
			array[2] = fileContent.substr(pos+2);
			fileContent = array[0] + array[1] + array[2];
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc != 4)
		return 1;
	
	std::string fileName = argv[1];
	std::string toBeReplaced = argv[2];
	std::string toReplace = argv[3];
	std::string fileContent;

	std::ifstream file(fileName);
	getFile(file, fileContent);
	file.close();

	replaceContent(fileContent, toBeReplaced, toReplace);

	std::ofstream newFile(fileName + ".replace");
	newFile << fileContent;
	newFile.close();

	return 0;
}