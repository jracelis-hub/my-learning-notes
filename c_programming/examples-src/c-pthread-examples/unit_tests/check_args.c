#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

	if ( strlen(argv[1]) > 16 ||
         strncmp(argv[1], "192.",4) != 0 ||
         strncmp(argv[1], "172.",4) != 0 ||
         strncmp(argv[1], "10.",3) != 0) 
	{
		fprintf(stderr,"Error\n");
		return -1;
	}
	   
	printf("Good\n");
	return 0;
}
