#include <iostream>
#include <vector>

/* Quick Sort can be sorting from ascending or descening order
 * It requires a pivot 
 * The pivot is an element of choosing in an array
 * Step 1. Choose a pivot and place it in the corresponding spot
 * Step 2. Smaller values on the left of pivot
 *         Larger values on the right of pivot
 * Similar to merge sort use low and high locations
 * low
 * 4 6 2 5 10 33 1 0 
 *                 high
 * pivot
*/

void swap(int& low, int& high)
{
    int temp = low;
    low = high;
    high = temp;
}

/* This returns the parition to evaluate the quick sort recursion */
int partition(std::vector<int>& array, int low, int high) {
    /* pivot = array[0] = 4*/
    int pivot = array[low];
    int i = low;
    int j = high;
    while (i < j) {
        while (array[i])
    }

}

void quick_sort(std::vector<int>& array, int low, int high )
{
    /* base case if low is less than high */
    if (low < high) {
        /* Pivot is used to split the array into seperate arrays */
        int pivot = partition(array, low, high);
        quick_sort(array, low, pivot);
        quick_sort(array, pivot + 1, high);
    }
}

int main()
{
    std::vector<int> array = {5, 2, 3, 1, 7, 10};

    quick_sort(array, 0, array.size() - 1);

    return 0;
}