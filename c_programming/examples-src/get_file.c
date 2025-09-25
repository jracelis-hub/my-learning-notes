#include <stdio.h>
#include <string.h>

void command_get_file(char *request, char *file, int size)
{
	int i = 0;
	char *p;

	for (p = request; *p != '\n'; p++)
	{
		if (*p == ';' || *p == ' ')
		{
			request = p;
			request++;
		}
		if (!strncmp(p,"..",2))
			request = p;
	}

	while(*request != '\0' && *request != '\n' && i < size - 1)
	{
		file[i++] = *request++;
	}
	file[i] = '\0';
}


int main()
{
	char file[128];
	memset(file,0,sizeof(file));

	char file_path[] = "Download; ../thisis/a/fail.txt\n";

	command_get_file(file_path, file, 128);

	printf("%s\n",file);
	printf("%s",file_path);


	return 0;
}
