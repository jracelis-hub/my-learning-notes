#include <stdio.h>

char *getCommand(char *input)
{
	char *p = NULL;
	for (p = input; *p = '\0'; p++) {
		if (*p == ';') {
			input = p;
			input++;
			return input;
		}
		if (*p == '\n') {
			*p = '\0';
			return input;
		}
	}
	return NULL;
}

int main() 
{
	char command_s[] = "Download; hello";

	char *command = getCommand(command_s);
	printf("%s\n", command);
	
	return 0;
}
