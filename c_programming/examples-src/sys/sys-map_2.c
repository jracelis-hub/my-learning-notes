#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define PAGE_SIZE 4096

int main()
{
	int fd;

	fd = open("files.txt", O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Could not open file\n");
		return -1;
	}
	printf("Open file\n");

	char *mapped_location = mmap(NULL, PAGE_SIZE, PROT_READ, MAP_SHARED, fd, 0);
	if (mapped_location == (void *)-1)
	{
		fprintf(stderr, "Could not create mapped location\n");
		close(fd);
		return -1;
	}

	close(fd);

	printf("%s", mapped_location);

	return 0;
}
