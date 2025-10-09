#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096

/* mmap() creates a new map in virtual space compared to brk usually
 * handling heap allocation in lower pages */
/* map(address/NULL, PAGE_SIZE, MODE(READ/WRITE), MAP_SHARED, file_descriptor, ) */

int main()
{
	const char *file_name = "files.txt";
	char kill;
		
	int fd = open(file_name, O_RDWR);
	if (fd < 0)
	{
		fprintf(stderr, "Could not open file\n");
		return -1;
	}
	printf("Opened file\n");

	/* mmap returns a pointer to the location where to memory is mapped to */
	char *mapped_location = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (mapped_location == (void *)-1)
	{
		fprintf(stderr, "Could not allocate space\n");
		close(fd);
		return -1;
	}
	printf("Created map\n");

	close(fd);

	int i = 0;
	while (1) 
	{
		printf("Enter character: ");
		scanf("%c", &kill);
		if (kill = 'k')
		{
			printf("Unmapping\n");
			break;
		}
	}

	if (munmap(mapped_location, PAGE_SIZE) != 0)
	{
		fprintf(stderr, "Could not close mapped location\n");
		exit(1);
	}
	printf("Closed map\n");
	
	return 0;
}
