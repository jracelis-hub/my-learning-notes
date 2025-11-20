#include <iostream>
#include <vector>

/* Binary Search Algorithm
 * Time Complexity = O(log n)
 * Space Complexity = O(1)
*/

/* Index = array location
 * Element = value at index
 */

/* The requirement for binary_search is that it needs to be an sorted array */
int binary_search(std::vector<int>& sorted_array, int target) {
    /* The first index in the array */
    int first_index = 0;
    /* The last index in the array */
    int last_index = sorted_array.size() - 1;
    /* Mid_index is the index that is compared to the target value */
    int mid_index;

    /* Compares first index is less than or equal to last index */
    while (first_index <= last_index) {
        mid_index = (last_index + first_index)/ 2;
        /* If sorted_array[mid_index] is == target return the index */
        if (sorted_array[mid_index] == target) { return mid_index; }
        else if (sorted_array[mid_index] < target) { first_index = mid_index + 1; }
        else { last_index = mid_index - 1; }
    }
    return -1;
}

int main() 
{
    std::vector<int> test_array = {1, 3, 5, 6, 7, 9, 10, 15};
    
    int index = binary_search(test_array, 0);

    std::cout << "Index = " << index << std::endl;

    return 0;
}