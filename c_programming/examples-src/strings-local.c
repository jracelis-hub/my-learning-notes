#include <stdio.h>

/* This prints out an error 
   Local buffer is not seen inside the function
   print_msg                                 */
void print_msg(void) {
	
	const char *msg = "This is local";
	snprintf(local_buffer,256,"%s\n",msg);
	printf("%s",local_buffer);
}

int main() {

	char local_buffer[256] = {0};

	print_msg();

	return 0;
}
