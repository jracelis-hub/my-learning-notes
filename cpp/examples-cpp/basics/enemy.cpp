#include <iostream>
#include "enemy.h"

/* Use Enemy& when modifying the value of enemy 
 * Use Enemy if returning a new copy or result of the object
 */

/* You can set default values by setting the values as is */
Enemy::Enemy(int h = 100, std::string n = "Enemy") : health(h), name(n) {}

Enemy& Enemy::operator-=(int damage) 
{
	std::cout << "Took " << damage << std::endl;
	this->health -= damage;
	return *this;
}

Enemy& Enemy::operator+=(int restore)
{
	std::cout << "Restoring " << restore << " health" << std::endl;
	this->health += restore;
	return *this;
}

void Enemy::get_health()
{
	std::cout << "Health = " << this->health << std::endl;
}

int main()
{
	Enemy monster;

	monster.get_health();

	/* removes 40 health */
	monster -= 40;

	monster += 100;

	monster.get_health();

	return 0;
}
