#include <stdio.h>

int main()
{
	size_t size = sizeof(arr) / sizeof(int);

	int i;
	for (i = 0; i < size + 1; i++)
		printf("%d\n",*(arr+i));

	return 0;
}
