#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	std::ifstream input_file;
	std::string str;

	input_file.open(argv[1]);
	if (input_file.fail()) 
	{
		std::cerr << "Could not open file" << std::endl;
	}
	else 
	{
		while (!input_file.eof())
		{
			getline(input_file, str);
			std::cout << str << std::endl;
		}
	}

	input_file.close();

	return 0;
}
