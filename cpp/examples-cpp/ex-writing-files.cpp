#include <iostream>
#include <string>
#include <fstream>

int main() 
{
	/* Reading rather than creating FILE* infile you create a specific
	 * object to handle input stream using std::ifstream inFile */
	std::ofstream outFile;
	float a;


	outFile.open("testing.txt");
	/* This checks if the file was opened */
	if (outFile.fail()) {
		std::cout << "File not found!" << std::endl;
	}
	else {
		std::cout << "Enter a value: ";
		std::cin >> a;
		outFile << "a = " << a << std::endl;
		outFile.close();
	}

	return 0;
}
