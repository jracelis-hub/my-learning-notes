#include <iostream>
#include <string>
#include <fstream>

int main() 
{
	/* Reading rather than creating FILE* infile you create a specific
	 * object to handle input stream using std::ifstream inFile */
	std::ifstream inFile;
	std::string str;
	int number;
	char letter;

	inFile.open("helloWorld.cpp");
	/* This checks if the file was opened */
	if (inFile.fail()) {
		std::cout << "File not found!" <<std::endl;
	}
	else {
		while (!inFile.eof()) {
			/* Getting line from the stream inFile
			 * placing it into the buffer str   */
			getline(inFile, str);
			std::cout << str << std::endl;
		}
		inFile.close();
	}

	return 0;
}
