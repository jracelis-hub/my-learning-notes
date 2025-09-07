#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	if ( argc < 3 ) {
		fprintf(stderr,"%s needs the path of the directory\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	DIR *dir_fd = opendir(argv[1]);
	if ( dir_fd == NULL ) {
		fprintf(stderr,"Could not open %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}

	struct dirent *directory;

	while ( (directory = readdir(dir_fd)) != NULL ) {
		if ( strcmp(directory->d_name,".") == 0  || 
		     strcmp(directory->d_name,"..") == 0 ||
		     strncmp(directory->d_name,".",1) == 0 ) { continue; }
		if ( strcmp(argv[2],directory->d_name) == 0) { 
			printf("Found file\n");
			break; 
		}
	}

	closedir(dir_fd);
	return 0;
}
