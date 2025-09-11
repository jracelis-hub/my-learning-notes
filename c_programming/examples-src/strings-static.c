#include <stdio.h>
#include <string.h>

static char global_buffer[256] = {0};

void message(void) {

	const char* msg = "This is a function";
	memset(global_buffer,0,256);	

	snprintf(global_buffer,256,"%s\n",msg);
	printf("%s",global_buffer);
}

int main() {

	const char* words = "hello world";

	snprintf(global_buffer,256,"%s\n",words);
	
	printf("%s",global_buffer);

	message();

	return 0;
}
