#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

	if ( argc < 2 ) {
		fprintf(stderr,"%s needs one arguments\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	const int buffer = 4056;
	int f_fd;
	char message[buffer];
	ssize_t bytes;

	f_fd = open(argv[1],O_RDONLY);
	if ( f_fd == -1 ) {
		fprintf(stderr,"Unable to open file\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n",f_fd);

	lseek(f_fd,0,SEEK_SET);

	/* Ensure that the buffer is clear */
	memset(message,0,sizeof(message));
	bytes = read(f_fd,message,buffer - 1);
	if ( bytes == -1 ) {
		fprintf(stderr,"Could not read from the filen\n");
		exit(EXIT_FAILURE);
	}

	printf("Bytes: %zu\n", bytes);
	message[bytes] = '\0';

	printf("%s",message);
	
	close(f_fd);

	return 0;
}
