#include <stdio.h>
#include <string.h> 

char *return_request(char *request)
{
	char *p;
	for (p = request; *p != '\0'; p++)
	{
		if (*p == ';') 
			*(p + 1) = '\0';
		else if (*p == '\n')
			*p = '\0';
	}
	return request;
}

int main()
{
	char request[] = "Download; file.txt\n";
	
	char *something = return_request(request);

	printf("%s\n",something);

	return 0;
}
