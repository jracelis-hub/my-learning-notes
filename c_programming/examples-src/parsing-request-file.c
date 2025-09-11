#include <stdio.h>

char *parse_file(char *request) {

	int i;
	char *temp = NULL;

	for (i=0; *(request+i) != '\0';i++) {
		if ( *(request+i) == ';' || 
		     *(request+i) == ' ' || 
			 *(request+i) == '/' ) 
		{
			temp = (request+i);
		}
		if ( *(request+i) == '\n' ) {
			*(request+i) = '\0';
			break;
		}
	}
	
	if (temp)
		return temp + 1;
	else
		return NULL;

}

int main() {

	char request[] = "List; /file/file/random\n";

	char *something = parse_file(request);	

	printf("%s\n",something);

	return 0;
}
