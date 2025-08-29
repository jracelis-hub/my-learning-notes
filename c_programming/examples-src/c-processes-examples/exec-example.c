#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	int status;	

	status = execve("./hello","hello",NULL);
	if ( status == -1 ) {
		fprintf(stderr,"Could not execute /bin/ls\n");
		exit(1);
	}

	return 0;
}
