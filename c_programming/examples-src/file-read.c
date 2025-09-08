#include <stdio.h>
#include <string.h>

/* This program is just to read data from a file */
/* It prompts you to determine the absolute path of the file */

int get_filepath(char path[],const int buffer);

int main(void) {
	
	FILE *fh;
	const char *mode = "r+";

	int c = 0;

	const int buffer = 64;
	char path[buffer];

	get_filepath(path,buffer);
	printf("%s\n",path);

	fh = fopen(path,mode);
	if ( fh = NULL ) {
		printf("Could not open file...\n");
		fclose(fh);
		return -1;
	}

	while( (c = getc(fh) != EOF)  && (c != '\n') ) {
		putchar(c);
	}

	fclose(fh);

	return 0;
}

int get_filepath(char path[],const int buffer) {
		
	int path_len;
	path_len = 0;

	printf("Enter file path: ");
	fgets(path,buffer,stdin);

	path_len = strnlen(path,buffer);
	path[path_len-1] = '\0';

	if ( path[0] != '/' ) {
		printf("%s needs to start with /\n",path);
		return -1;
	}

	return 0;
}





