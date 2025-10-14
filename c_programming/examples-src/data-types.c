#include <stdio.h>
#include <string.h>

/* size_t = long unsigned int */
/* strlen = long unsigned int */
/* ssize_t = long int */
typedef unsigned long uint;

int main()
{

	printf("size_t = long unsigned int\n");
	printf("strlen() = long unsigned int\n");
	printf("ssize_t = long int\n");

	printf("sizeof(%s) = %lu byte = %lu bits\n", "char", sizeof(char), sizeof(char) * 8);
	printf("sizeof(%s) = %lu byte = %lu bits\n", "unsigned char", sizeof(unsigned char), sizeof(unsigned char) * 8);
	printf("sizeof(%s) = %lu bytes = %lu bits\n", "short", sizeof(short), sizeof(short) * 8); /* The same as short int */
	printf("sizeof(%s) = %lu bytes = %lu bits\n", "unsigned short", sizeof(unsigned short), sizeof(unsigned short) * 8); /* The same as short int */
	printf("sizeof(%s) = %lu bytes = %lu bits\n", "int", sizeof(int), sizeof(int) * 8);
	printf("sizeof(%s) = %lu bytes = %lu bits\n", "unsigned int", sizeof(unsigned int), sizeof(unsigned int) * 8);
	printf("sizeof(%s) = %lu bytes = %lu bits\n", "long", sizeof(long), sizeof(long) * 8); /* The same as long int */
	printf("sizeof(%s) = %lu bytes = %lu bits\n", "unsigned long", sizeof(unsigned long), sizeof(unsigned int) * 8); /* The same as long int */
	printf("sizeof(%s) = %lu bytes = %lu\n", "long long", sizeof(long long), sizeof(long long) * 8); /* The same as long long int */
	printf("sizeof(%s) = %lu bytes = %lu bits\n", "unsigned long long", sizeof(unsigned long long), sizeof(unsigned long long) * 8); /* The same as long long int */
	printf("Floating point numbers\n");
	printf("sizeof(%s) = %lu bytes = %lu bits\n", "float", sizeof(float), sizeof(float) * 8); /* The same as long long int */
	printf("sizeof(%s) = %lu bytes = %lu bits\n", "double", sizeof(double), sizeof(double) * 8); /* The same as long long int */


	return 0;
}
