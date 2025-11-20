#include <iostream>

int main() 
{
	int highScore[] = {100, 99, 89, 99};
	int *pHighScore = &highScore[3]; /* pHighscore is holding the address of highScore[3] = 99 */

	std::cout << "The high score of highScore[3] = " << *pHighScore << std::endl;

	return 0;
}
