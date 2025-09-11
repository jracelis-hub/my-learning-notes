#include <stdio.h>
#if defined(DEBUG) && !defined(INET)
	#define INET
#endif

int main() {

#if defined(DEBUG)
	printf("Debug build\n");
#endif
	
#if defined(INET)
	printf("INET enabled\n");
#endif

	return 0;
}
