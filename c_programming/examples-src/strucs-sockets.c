#include <stdio.h>

#define BUFFER 4096 /* 4 kib */

enum Command_types {
	DOWNLOAD,
	UPLOAD,
	LIST,
	READ,
};

struct command_t {
	
	char request[BUFFER];
	char reply[BUFFER];
	char directory[256];
	int socket_fd;
};

int main(int argc,char *argv[]) {
	
	struct command_t command;

	return 0;
}
