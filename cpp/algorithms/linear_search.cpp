#include <iostream>
#include <string>

/* Linear Search 
 * Time Complexity O(n)
 * Space Complexity O(1)
 */

/* Has to be a linear data structure */

int linear_search(std::string& sentence, char target) {
    for (int length = 0; length < sentence.length(); length++) {
        if (sentence[length] == target) {
            return length;
        }
    }
    return -1;
}

int main()
{
    std::string name = "Jarron Racelis";

    int index = linear_search(name, 'z');

    std::cout << "Index = " << index << std::endl;

    return 0;
}