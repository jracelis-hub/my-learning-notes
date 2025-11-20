#include <stdio.h>
#include <stdbool.h>

void swap(int *left, int *right) 
{
    int temp = *left;
    *left = *right;
    *right = temp;
}

void bubble_sort(int *array, size_t array_size)
{
    bool swapped = false;
    do
    {
        swapped = false;
        for (int j = 0; j < array_size - 1; j++) 
        {
            if (array[j] > array[j + 1]) 
            {
                swap(&array[j], &array[j + 1]);
                swapped = true;
            }
        }
    } while (swapped);
    
}

void print_array(int *array, size_t array_size)
{
    for (int i = 0; i < array_size; i++) 
    {
        printf("Array[%d] = %d\n", i, array[i]);
    }
}

int main()
{
    int array[] = {1, 10, 33, 23, 2, 4, 32};
    size_t size = sizeof(array) / sizeof(int);

    bubble_sort(array, size);

    print_array(array, size);

    return 0;
}