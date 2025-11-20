#include <stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void insertion_sort(int *array, size_t size)
{
	int i, j;
	for (i = 1; i < size; i++)
	{
		j = i;
		while (j > 0 && array[j - 1] > array[j])
		{
			swap(&array[j - 1], &array[j]);
			j--;
		}
	}
}

void print_array(int *array, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}

}

int main()
{
	int array[] = {3, 5, 32, 22, 1, 30};
	size_t size = sizeof(array)/ sizeof(int);

	insertion_sort(array, size);

	print_array(array, size);

	return 0;
}
