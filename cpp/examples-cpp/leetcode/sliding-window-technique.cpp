#include <iostream>
#include <array>


/* what is sliding window technique
 * There is two implementations 
 * Fixed - the window stays at a fixed size based on given parameters
 * Dynamic - increases the window dynamically either increase or decreased based on requirements
 *
 * A sliding window requires two pointers:
 * Ill describe the two pointers as the beginning of the window and the end of the window
 *
 *     beginning
 *       |
 *      \|/
 *     -------------------------
 *     | 0 | 1 | 3 |   |   |   |
 *     -------------------------
 *              /|\
 *               |
 *              end
 *
 * depending on the sub set the window will sliding left to right 
 * 
 *     
 * */            

/* Question 1: Statically Sized Sliding Window 
 * Context:
 * Subarray Size: 2 
 * Given n numbers in an array, find the max sum subarray of the required size */
class Solution {
public:
	int maxSum(const std::array<int>& an_array) {
		int currentSum = 0;
		int start = 0;
		for (int end = 0; end < an_array.size(); end++) {

		}

	}
};

/* Question 2: Given an array of positive integers, find the subarrays that add up to a given number 
 * */

int main()
{
	std::array<int> question = [-1, 2, 3, 1, -3, 2];

	return 0;
}
