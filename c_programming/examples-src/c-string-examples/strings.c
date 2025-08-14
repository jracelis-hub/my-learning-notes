#include "my_string.h"

int my_str_len(const char *string) {
	int length;
	for(int i=0; string[i] != '\0'; i++) {
		length++;
	}

	return length;	
}

char *my_str_tok(char *string, const char tok) {
	int i=0;
	while ( string[i] != '\0' ) {
		i++;
		if ( string[i] == tok ) {
			string[i] = '\0';
			break;
		}
	}
	return string;
}

void my_str_cpy(char *dst, const char *src) {
	
	for(int i=0; src[i] != '\0';i++) {
		dst[i] = src[i];
	}
}
