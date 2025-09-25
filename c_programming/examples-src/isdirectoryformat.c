#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isdirectoryformat(char *directory)
{
	bool dir = true;
	size_t len = strlen(directory);
	printf("Length = %lu\n",len);
	
	if (*(directory + len - 1) == '/')
		return dir;

	dir = false;
	return dir;
}

int main(int argc, char *argv[]) 
{
	if (argc != 2)
		return -1;

	size_t len;

	if (!isdirectoryformat(argv[1]))
	{
		printf("Adding /\n");
		strcat(argv[1],"/");
	}

	printf("%s\n",argv[1]);

	return 0;
}
