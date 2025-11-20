#include <iostream>
#include <vector>

/* Merge sort is a divide and conquer approach it splits them up at lowest
 * of 2 indexes then grows by 2
 * [1, 33, 45, 10, 2, 21, 55] Split Down The Middle
 *    |         |     |     |
 * [1, 33] [45, 10] [2, 21] [55]
 * [1] [33] [45] [10] [2] [21] [55]
 * [1, 33] [10, 45] [2, 21] [55]
 * [1, 33, 10, 45] [2, 21, 55]
 * [1, 2, 10, 21, 33, 45, 55]
 */


 /* int l = index at the most left of the array
  * int r = index at the most right of the array
  */
void merge_sorted_arrays(std::vector<int>& a, int left_index, int mid_index, int right_index) {
    /* 5 - 0 + 1 = 6*/
    int left_length = mid_index - left_index + 1;
    /* 10 - 5 = 5*/
    int right_length = right_index - mid_index;

    /* Create arrays to store the temporary values */
    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;

    for (i = 0; i < left_length; i++)
    {
        temp_left[i] = a[left_index + i];
    }

    for (i = 0; i < left_length; i++)
    {
        temp_right[i] = a[mid_index + 1 + i];
    }

    for (i = 0, j = 0, k = left_index; k <= right_index; k++) {
        /* temp_left <= temp_right */
        if ((i < left_length) && (j >= right_length || temp_left[i] <= temp_right[j])) {
            a[k] = temp_left[i];
            i++;
        } else {
            a[k] = temp_right[j];
            j++;
        }
    }
}

void merge_sort_recursion(std::vector<int>& unsorted_array, int left_index, int right_index) {
    if (left_index < right_index) {
        /*                   0     +         (10 - 0)           / 2 */
        int mid_index = left_index + (right_index - left_index) / 2;
        /* mid_index = 5 */

        merge_sort_recursion(unsorted_array, left_index, mid_index);
        merge_sort_recursion(unsorted_array, mid_index + 1, right_index);

        merge_sorted_arrays(unsorted_array, left_index, mid_index, right_index);
    }
}

void merge_sort(std::vector<int>& unsorted_array) {

    /* Takes left index and right index */
    merge_sort_recursion(unsorted_array, 0, unsorted_array.size() - 1);
}

int main()
{
    std::vector<int> a = {9, 4, 2, 1, 3, 6, 8, 7, 3, 55};

    merge_sort(a);

    for (int number : a) {
        std::cout << number << std::endl;
    }

    return 0;
}