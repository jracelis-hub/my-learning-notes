#include <stdio.h>

char global_buffer[256] = {0};

int main() {

	const char *words = "Hello World";

	snprintf(global_buffer,256,"%s\n",words);

	printf("%s",global_buffer);

	return 0;
}
