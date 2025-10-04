#include <iostream>
#include <string>

/* Passing values by reference `&` is good because it
   does not have to make a copy of that on the stack
   when passing the value by reference memory 
   was already allocated on the stack            */

std::string getPlayerName(void)
{
	return "Jarron";
}

int calculateScore(int score, int times_score)
{
	return score * times_score;
}

/* Letting them know the value is just being passed in to be used
   so const is adding the guard rails to make sure it is known
   that the value player is just being used for its value and 
   nothing more                                            */
void displayScore(const std::string& playerName, int score)
{
	std::cout << playerName << " scored: " 
	<< score <<  " points." << std::endl;
}

int main()
{
	std::string playerName = getPlayerName();
	int score = calculateScore(75, 2);

	displayScore(playerName, score);

	return 0;
}
