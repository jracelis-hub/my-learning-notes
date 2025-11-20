#include <stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selection_sort(int *array, size_t array_size)
{
	int minimum;
	for (int i = 0; i < array_size - 1; i++)
	{
		minimum = i;
		for (int j = i + 1; j < array_size; j++)
		{
			if (array[j] < array[minimum])
			{
				/* minimum gets updated */
				minimum = j;
			}
		}
		/* once the absolute minimum is found swap minimum with the index of i */
		swap(&array[i], &array[minimum]);
	}

}

void print_array(const int *array, size_t array_size)
{
	for (int i = 0; i < array_size; i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}
}

int main()
{
	int array[] = {3, 10, 2, 21, 1, 6};
	
	size_t size = sizeof(array) / sizeof(int);

	selection_sort(array, size);

	print_array (array, size);

	return 0;
}
