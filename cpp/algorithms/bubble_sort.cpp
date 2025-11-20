#include <iostream>
#include <vector>

/* Bubble Sort loops through the array by the size of the array
 * Time complexitiy O(n^2) it is not efficient and not recommended to use
 * Space complexity O(1)
 *
 * Uses adjecent swapping
 * if the left value is great than right value swap them
 * Note: if want ascending order left > right swap
 *       if want descending order right < left swap
 * 1st loops through the array n times
 * 2nd loop controls the swapping from n - 1 times
 * it is n - 1 because the last index does not get compared to anything
 */

void swap(int& left, int& right) {
    int temp = left;
    left = right;
    right = temp;
}

void bubble_sort(std::vector<int>& unsorted_array) {
    /* The first loop is the number of passes it goes through based on the 
     * size of the array
     * if the size() = 10 the loop will pass through 10 times
     */
    int number_passes;
    for (number_passes = 0; number_passes < unsorted_array.size(); number_passes++) {
        /* Not comparing the last number because it can not 
         * compare anything hence unsorted_array.size() - 1 
         * 1 2 3 4 5 6 7 |8|
         * subtracting the numbers passes is because every 2nd loop
         * the largest value will always be at the end
         * 1st pass 3 2 4 8 5 10
         * 2nd pass 2 3 4 5 8 10
         */
        for (int j = 0; j < unsorted_array.size() - 1 - number_passes; j++) {
            /* If left is greater than right swap */
            if (unsorted_array[j] > unsorted_array[j + 1]) {
                swap(unsorted_array[j], unsorted_array[j + 1]);
            }
            /* If want bubble sort in desending order compare if 
             * left is < right then swap
            if (unsorted_array[j] < unsorted_array[j + 1]) {
                swap(unsorted_array[j], unsorted_array[j + 1]);
            }
            */
        }
    }
    std::cout << "Passes = " << number_passes << std::endl;
}

void bubble_sort_efficent(std::vector<int>& unsorted_array) {
    bool swapped = false;
    int i = 0;
    do
    {
        /* After each iteration it reset the */
        swapped = false;
        for (int j = 0; j < unsorted_array.size() - 1 - i; j++) {
            if (unsorted_array[j] > unsorted_array[j + 1]) {
                swap(unsorted_array[j], unsorted_array[j + 1]);
                swapped = true;
            }
        }
        i++;
    } while (swapped); /* This condition if true */
    std::cout << "Passes = " << i << std::endl;
}

void print_sorted(std::vector<int>& sorted) {
    for (int i = 0; i < sorted.size(); i++) {
        std::cout << "Array[" << i << "] = " << sorted[i] << std::endl;
    }
}

int main() 
{
    std::vector<int> unsorted_array = {33, 10, 2, 3, 4, 5, 10, 33};

    bubble_sort_efficent(unsorted_array);

    print_sorted(unsorted_array);

    return 0;
}
