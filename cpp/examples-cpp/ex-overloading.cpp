#include <iostream>

int getSpeed(int speed, int multiplier)
{
	return speed * multiplier;
}

double getSpeed(double speed, int multiplier)
{
	return speed * multiplier;
}

int main()
{
	int speed = getSpeed(10, 2);
	double dSpeed = getSpeed(3.3, 2);

	std::cout << "Speed in int = " << speed << std::endl;
	std::cout << "Speed in int = " << dSpeed << std::endl;

	return 0;
}
