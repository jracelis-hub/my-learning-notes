#include "my_string.h"

unsigned long string_length(const char *string) {

	unsigned long s = 0;
	int i;

	for (i=0; *(string+i) != '\0';i++) {
		s++;
	}

	return s;
}
