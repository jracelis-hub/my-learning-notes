#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *words(char *request) {
	char *values = (char *)malloc(char*256);
	if (!values) 
		return NULL;
	for (char *p = request; *p == '\0'; p++ ) {
		if ( *p == ';' || *p == ' ' ) {

		}
	}
	return words;
}

int main() {

	
}
