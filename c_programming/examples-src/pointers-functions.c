#include <stdio.h>

float add(float x,float y) 
{
	return x+y;
}

float sub(float x,float y) 
{
	return x-y;
}

void hello(void) {
	printf("Hello World\n");
}

int main() {

	/* To declare a function pointer first declare the data type the function returns
	   Example: void (*func_name)
	   Next place the arguments that the function takes 
       Example: void (*func_name)(void *)                                          */
	float (*pfunction)(float, float);
	void (*phello)(void) = hello;

	phello();
	pfunction = sub;

	printf("%f\n",(*pfunction)(3,4));

	return 0;
}
