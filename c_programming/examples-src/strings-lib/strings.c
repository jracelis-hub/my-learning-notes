#include "my_string.h"
#include <stdio.h>

unsigned long string_length(const char *string) {

	unsigned long i = 0;

	for (i=0; *(string+i) != '\0'; i++)
		;

	return i;
}

int main()
{
	const char *words = "Words\n";
	unsigned long len = string_length(words);
	
	printf("Count = %lu\n",len);
	
	return 0;
}
