#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) 
{
	if ( argc != 2 )
	{
		fprintf(stderr,"%s needs 1 argument\n",argv[0]);
		return -1;
	}

	struct stat file_info = {0};

	int status = stat(argv[1],&file_info);
	if ( status != 0 ) 
	{
		fprintf(stderr,"Could not get file info of %s\n",argv[1]);
#ifdef DEBUG
		printf("Status code: %d\n",status);
#endif
		return -1;
	}

	printf("%s size: %jd bytes\n",
           argv[1],
	       (long unsigned int)file_info.st_size);

	return 0;
}
