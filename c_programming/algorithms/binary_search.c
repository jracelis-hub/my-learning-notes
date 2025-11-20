#include <stdio.h>

int binary_search(int *array, int target, size_t array_size) 
{
    int left_index = 0;
    int right_index = array_size - 1;

    int mid_index;
    while (left_index <= right_index) 
    {
        /* 10 - 0 / 2 = 5 */
        mid_index = right_index - left_index / 2;
        /* Returns the index value where the target is located at */
        if (array[mid_index] == target) { return mid_index; }
        else if (array[mid_index] < target) { left_index = mid_index + 1; }
        else { right_index = mid_index - 1; }
    }
    return -1;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 8, 10, 15};

    size_t size = sizeof(a) / sizeof(int);

    int index = binary_search(a, 3, size);

    printf("Target is found in index %d\n", index);

    return 0;
}