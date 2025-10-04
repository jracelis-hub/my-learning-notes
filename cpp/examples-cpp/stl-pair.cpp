#include <iostream>
#include <array>
#include <string>

int main()
{
	std::pair<int, char> p = {1, 'a'};
	/* To store pairs of pairs do the following */
	std::pair<int, std::pair<int, std::string>> p2 = {1, {2, "Jarron"}};

	std::cout << p.first << " " << p.second << " " << std::endl;

	/* p2.second.first access the the 2 value of the first pair and the first value of the 2nd pair */
	std::cout << p2.first << " " << p2.second.first << " " << std::endl;

	/* Storing an array of pairs of type int */
	std::pair<int, int> arr[] = { {7, 6}, {1, 5}, {3, 4}};
	
	/* To access each pair int the array 
	 * this arr[0] is the first index and 
	 * .first is the first array in that
	 * index                            */
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; i++) {
		std::cout << arr[i].first << std::endl;
		std::cout << arr[i].second << std::endl;
	}


	return 0;
}
