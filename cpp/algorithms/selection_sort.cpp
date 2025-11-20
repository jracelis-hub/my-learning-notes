#include <iostream>
#include <vector>

/* Selction sort is the opposite of bubble sort 
 * selection sort all the values to the left
 * while bubble sort sorts all the items to the right
 * Time complexity O(n^2)
 * Space complexity O(1)
 */

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void selection_sort(std::vector<int>& a)
{
	int minimum;
	for (int i = 0; i < a.size() - 1; i++)
	{
		/* first set the minimum value at the first index */
		minimum = i;
		for (int j = i + 1; j < a.size(); j++)
		{
			/* if a[j] is less than the value at minimum it updates the new miniumum */
			if (a[j] < a[minimum]) 
			{
				minimum = j;	
			}
		}
		swap(a[i], a[minimum]);
	}
}


int main()
{
	std::vector<int> a = {5, 10, 2, 3, 22, 1, 100, 32};

	selection_sort(a);

	for (int number : a) {
		std::cout << number << std::endl;
	}
	
	return 0;
}
