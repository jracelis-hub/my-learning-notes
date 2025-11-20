#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
private:
	int health;
	std::string name;

public:
	Enemy(int h, std::string n);

	Enemy& operator-=(int damage);

	Enemy& operator+=(int restore);

	void get_health();

	~Enemy() {}

};

#endif /* ENEMY_H */
