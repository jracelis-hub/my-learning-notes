#include <stdio.h>

void merge_array(int array, int left, int mid, int right)
{
	/* i points the temporary variable of the left index 
	 * j point the temporary variable of the right index
	 * k point to the actual array */
	int i, j, k;

	int length_left = mid;
	int length_right = right - mid;

	int temp_r[length_right];
	int temp_l[length_left];

	for (int i = 0; i < length_left; i++)
	{
		temp_l[i] = array[i];
	}
}

/* left is always 0
 * right = sizeof array - 1 */
void merge_sort(int *array, int left, int right)
{
	if (left < right) {
		int mid = (right - left) / 2;
		merge_sort(array, left, mid);
		merge_sort(array, mid + 1, right);
		merge_array(array, left, mid, right)
	}

}

int main()
{


}
