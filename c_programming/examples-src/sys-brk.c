#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define PAGE_SIZE 4096

/* The sbrk sys call extends the data segment up to allocating
 * memory on the heap the heap is usually extended by the page
 * size which is usualy 4 KiB or 4096 Bytes                */

/*
 * -------------------------
 * |         Heap          |
 * |                       |
 * ------------------------- <---- void *endDataSegment = sbrk(PAGE SIZE);
 * |     Data Segment      |
 * |                       |
 * -------------------------
 * |        Code           |
 * |                       |
 * -------------------------
 */

int main()
{
	/* To create a */
	void *endDataSegment = NULL;

	endDataSegment = sbrk(PAGE_SIZE);

	/* Using brk to "free" the allocated memory */
	if (brk(endDataSegment) != 0) {
		fprintf(stderr, "Could not free memory... Force exit\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
