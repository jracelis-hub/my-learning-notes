#include <stdio.h>

void merge_array(int *array, int low, int mid, int high)
{
    int left_length = mid - low + 1;
    int right_length = high - mid;

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;
    for (i = 0; i < left_length; i++)
    {
        temp_left[i] = array[i];
    }

    for (i = 0; i < right_length; i++)
    {
        temp_right[i] = array[i];
    }

	i = j = k = 0;
    while ((i < left_length) && (j >= right_length || temp_left[i] <= temp_right[j]))
    {
		if (temp_left[i] <= temp_right[j])
		{
			array[k] = temp_left[i];
			i++;
		}
		else
		{
			array[k] = temp_right[j];
			j++;
		}
    }

}

/* low is always 0
 * high is the size of the array - 1 (Since index start at 0)
 * [3, 2, 4, 1, 5]
 * low         high
 * [3, 2, 4]    [1, 5]
 * It is important that the values are just being passed just as a range
 * the merge sort is taking a range of values for instance from 0 - 10
 * then from 0 5 (left)
 * from 6 10 (right)
 */ 
void merge_sort(int *array, int low, int high)
{
    /* since using recursion need a base to stop recursion */
    if (low >= high) { return; }
    int mid = (low + high) / 2;

    /* This will keep calling until each array hits a size of 1 value each
    array, 3              
    */
    merge_sort(array, low, mid);
    /* This will now do the right side which is 2 and it will return
    */
    merge_sort(array, mid + 1, high);

    /* Its time to merge [3] [2] sorted */

    merge_array(array, low, mid, high);
}

int main()
{
	int array[] = {3, 2, 5, 1, 6, 7};
	size_t size = sizeof(array) / sizeof(int);

	merge_sort(array, 0, size - 1);

	for (int i = 0; i < size; i++) {
		printf("array[%d] = %d\n", i, array[i]);
	}

	return 0;
}
