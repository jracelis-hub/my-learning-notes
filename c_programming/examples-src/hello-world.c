#include <stdio.h>

char *found_token(char *string,const char token) {

	for (int i=0; *(string+i) != '\0'; i++) {
		if ( *(string+i) == token ) {
			return string+i;
		}
	}
	return NULL;
}
int main() {

	char *message = "Hello World\n";
	
	char *this = found_token(message,'o');
	if (!this) {
		printf("Could not find\n");
	} else {
		printf("Found\n");
		printf("%s\n",this);
	}

	return 0;
}
