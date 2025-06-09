#include <stdio.h>

long long int g_data = 0xFFFEABCD11112345;

int main(void) {

	char *pAddress1 = (char*) &g_data;
	
	printf("Value at address %p\n",pAddress1);
	printf("Value at address %p is: %x\n",pAddress1,*pAddress1);

	pAddress1 = pAddress1 + 1;
	printf("Value at address %p\n",pAddress1);
	printf("Value at address %p is: %x\n",pAddress1,*pAddress1);

	int *pAddress2 = (int*) &g_data;
	
	printf("Value at address %p\n",pAddress2);
	printf("Value at address %p is: %x\n",pAddress2,*pAddress2);

	pAddress2 = pAddress2 + 1;
	printf("Value at address %p\n",pAddress2);
	printf("Value at address %p is: %x\n",pAddress2,*pAddress2);
	return 0;
}
