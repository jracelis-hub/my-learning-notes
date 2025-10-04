#include <iostream>
#include <string>

void createZombie(const std::string& name = "Zombie", int health = 100)
{
	std::cout << "Name: " << name << std::endl << "Base health: " << health << std::endl;
}

int main()
{
	std::string name = "Jarron";
	createZombie(name);
	createZombie();

	return 0;
}
