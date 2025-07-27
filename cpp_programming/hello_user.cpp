#include <iostream>

int main() {
	char name[32];

	std::cout << "What is your name? ";
	std::cin >> name;

	std::cout << "Hi " << name << ",how are you doing?" << std::endl;

	return 0;
}

