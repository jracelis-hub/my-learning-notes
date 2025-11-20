#include <iostream>
#include <vector>

void swap(int &x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void insertion_sort(std::vector<int>& a)
{
	int i, j;
	for (i = 1; i < a.size(); i++)
	{
		j = i;
		/* j does not need to be 0 because the last 
		 * comparison is index 0 and 1 
         * 
		 */
		while (j > 0 && a[j - 1] > a[j])
		{
			swap(a[j], a[j - 1]);
			j--;
		}
	}
}

void print_array(const std::vector<int>& a)
{
	for (int number : a)
	{
		std::cout << number << std::endl;
	}
}

int main()
{
	std::vector<int> a = {5, 33, 2, 1, 14, 55};

	insertion_sort(a);

	print_array(a);

	return 0;
}
