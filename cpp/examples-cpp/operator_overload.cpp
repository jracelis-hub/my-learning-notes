#include <iostream>
#include <vector>
#include <string>

/* this is a pointer
   *this points the the object itself 
   Enemies zombie
   *this == zombie
 */

class Enemy {
/* private means only the declared class 
   object can manipulate the data of the following
   items
 */
private:
	std::vector<std::string> enemies_type;
	int enemies_left;
public:
	/* Default Constructor 
	   enemies_left set to 10 upon calling 
	*/
	Enemy() : enemies_left(10) 
	{
		std::cout << "Enemies left " << enemies_left << std::endl;
	}
	/* Overloaded Constructor 
	   taking a argument int enemies
	 */
	Enemy(int enemies) : enemies_left(enemies) 
	{
		std::cout << "Enemies left " << enemies_left << std::endl;
	}

	/* The virtual keyword makes it so that dervied classes
	 * can override the implementation and have their own
	 * way of using it 
	 */
	virtual void enter_noise()
	{
		std::cout << "Grrrrr!" << std::endl;
	}

	/* Operator overflow emplementation */
	Enemy operator+=(const std::string& enemiesName)
	{
		enemies_type.push_back(enemiesName);
		std::cout << "New enemy arrived " << enemiesName << std::endl;
		/* Returns *this which is current object */
		return *this;
	}
};

/* Use the following notation to create a derived class Zombie
   Zombie falls under Enemies 
   Zombie = Child (derived class)
   Enemy = Parent (base class)
 */
class Zombie : public Enemy {
private:

public:
	/* Polymorphism the base class Enemy and the derived class is Zombie */
	void enter_noise() override 
	{
		std::cout << "Ahhhhh" << std::endl;
	}
};

int main() 
{
	/* This uses default constructor */
	Enemy zombies;

	/* THis uses overloaded constructor */
	Enemy monsters = Enemy(55);

	/* Notice there is no Constructor
	   but it still uses the default constructor of
	   the base class
	 */
	Zombie zombie;

	/* Using operator overload function */
	monsters += "Zac";

	/* Since Zombie is a derived class of Enemy
	   zombie can use the same methods as Enemy */
	zombie += "Warwick";

	monsters.enter_noise();

	/* Polymorphism has different out compared to monsters.enter_noise() */
	zombie.enter_noise();

	return 0;
}
