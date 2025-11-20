#include <stdio.h>

int main()
{
	int number = 0;
	while (number != -1)
	{
		printf("Type -1 to exit\n");
		printf("Enter a number: ");
		scanf("%d", &number);
		printf("%d / 2 = %d\n", number, number / 2);
	}

	return 0;
}
