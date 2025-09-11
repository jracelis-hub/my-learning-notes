#include <stdio.h>
#include "my_string.h"

void *my_sizeof(void *data);

int main() {

#if defined(STRING)
	const char *words = "Hello\n";
	unsigned long strlen = string_length(words);

	printf("%lu\n",strlen);
#elif defined(MYSIZE)
	int i = 0;
	void *value = my_sizeof(&i);
	printf("%d\n",*(int *)value);
#endif
	return 0;
}
