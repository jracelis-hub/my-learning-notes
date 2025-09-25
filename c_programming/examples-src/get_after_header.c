#include <stdio.h>

char *strip_stuff(char *request)
{
	char *p;
	for (p = request; *p != '\0'; p++)
	{
		if (*p == ';' || *p == ' ' || *p == '/')
		{
			request = p;
			request++;
		}
		if (*p == '\n')
		{
			*p = '\0';
			return request;
		}
	}
	return NULL;
}

char *request_stuff(char *request)
{
	char *p;
	for (p = request; *p != '\n'; p++)
	{
		if (*p == '\0')
		{
			request = p;
			return ++request;
		}
	}

	return NULL;
}

int main()
{
	char request[] = "Upload; file.txt\nthis is random stuff";
	
	char *something = strip_stuff(request);
	printf("%s\n",something);
	char *random = request_stuff(request);
	
	printf("%s\n",random);

	return 0;
}
