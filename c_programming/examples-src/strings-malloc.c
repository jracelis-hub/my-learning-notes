#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_msg(char *buff) {
	
	const char *msg = "Hello World";
	snprintf(buff,256,"%s\n",msg);
	printf("%s",msg);
}

int main() {

	char *buffer = malloc(sizeof(char)*256);	
	if ( buffer == NULL ) {
		return -1;
	}

	memset(buffer,0,256);

	print_msg(buffer);
	
	free(buffer);
	return 0;
}
