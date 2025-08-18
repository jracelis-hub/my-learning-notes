#include <stdio.h>
#include <string.h>

/* Challenge Objective:
   --------------------
   Requirement 1:
   Create the file hello.txt for output
   Prompt the user for their name
   Write their name to the hello.txt file
   Output "[Name] has written to this file."

   Requirement 2:
   Reopen the file for reading
   Read in the single line of text stored in the file
   Output the line of text
   Add comments in the code to explain each explain each step taken 
*/

int main(int argc, char *argv[]) {

	if (argc == 1) {
		FILE *fh;
		const char *path = "hello.txt";
		const char *w_mode = "w";
		const char *r_mode = "r";

		int buffer = 33;
		char name[buffer];

		int c;

		/* To opening hello.txt in write mode */
		fh = fopen(path,"r+");
		if ( fh == NULL ) {
			fprintf(stderr,"Could not open file\n");
			return -1;
		}

		/* Get input from the user to write name to file */
		printf("Enter your name: ");
		if ( fgets(name,buffer-1,stdin) != NULL ) {
			int len = strlen(name);
			name[len-1] = '\0';

			/* Output what was entered to the screen */
			fprintf(fh,"%s has written to hello.txt.\n",name);
		}

		fclose(fh);

		/* Reopen hello.txt for read mode */
		fh = fopen(path,r_mode);

		if ( fh == NULL ) {
			fprintf(stderr,"Could not open file\n");
			return -1;
		}

		while ( (c = fgetc(fh)) != EOF && c != '\n' ) {
			putchar(c);
		}

		fclose(fh);

		return 0;
	}
	else {
		printf("%s, does not use arguments\n",argv[0]);
		return -1;
	}

}
