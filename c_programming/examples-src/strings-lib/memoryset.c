#include "my_string.h"
#include <stdio.h>

void *memoryset(void *s, int bytes, unsigned long size)
{
	int i;

	for (i = 0; i < size; i++)
		(((int *)s) + 1) = bytes;
	return s;
}

int main()
{
	int arr[] = {1, 2, 3};
	memoryset(arr, 0, sizeof(arr));

	int i;
	for (i = 0; i < 3; i++)
		printf("%d\n",arr[i]);
	return 0;
}
