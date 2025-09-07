#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	if ( argc < 2 ) {
		perror("error");
	}

	int fd;
	ssize_t bytes;
	const int buffer = 1024;
	char message[buffer];
	char file_read[256] = {0};
	char *file = "notes.txt";

	memset(message,0,sizeof(message));
	
	snprintf(file_read,sizeof(file_read)-1,"%s/%s",argv[1],file);

	fd = open(file_read,O_RDONLY);

	lseek(fd,0,SEEK_SET);

	bytes = read(fd,message,buffer-1);

	printf("%s\n",message);
	return 0;
}
