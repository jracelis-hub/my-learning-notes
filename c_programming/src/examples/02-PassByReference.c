#include <stdio.h>

void swap(int* a, int* b);

int main() {

	int a = 10;
	int b = 12;

	printf("The value of a: %d\n",a);
	printf("The value of b: %d\n",b);
	printf("The address for a is: %p\n", &a);
	printf("The address for b is: %p\n", &b);
	
	swap(&a,&b);
	printf("The value of a: %d\n",a);
	printf("The value of b: %d\n",b);
	printf("The address for a is: %p\n", &a);
	printf("The address for b is: %p\n", &b);

	return 0;
}

void swap(int* a, int* b) {
	
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
