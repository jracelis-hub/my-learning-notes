#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{

	if ( argc != 2 ) 
	{
		fprintf(stderr,"%s requires",argv[0]);
		return -1;
	}

	/* The struct stat is used to hold the file information
	 * Initializing the structure to be empty            */
	struct stat file_stats = {0};

	int status = stat(argv[1],&file_stats);
	if (status != 0) 
	{
		return -1;
	}

	printf("File size:%jd",file_stats.st_size);

	return 0;
}
