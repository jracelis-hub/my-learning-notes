#include "networking.h"
#include <stdlib.h>

void help(void) {
	printf("   Usage: This is an interactive client API.\n");
	printf("          Enter port and IPv4 address as prompted.\n");
	printf("          This will connect you to open sockets.\n");
	printf("          Sample\n");
	format(55,'-');
	printf("    Port: 8080\n");
	printf("    IPv4: 192.168.0.245\n");
	format(55,'-');
}


void format(const int count, const char character) {

	int i;
	for (i=0; i < count; i++) {
		putchar(character);
	}

	printf("\n");
}

void error_msg(const char *msg) {
	printf("%s\n",msg);
}

int get_port(char port[],const int buffer) {
	
	int len = 0;
	int i_port = 0;

	printf("      Enter PORT: ");
	if ( fgets(port,buffer,stdin) == NULL ) {
		return -1;
	} else if ( (i_port = atoi(port)) < 1023 ) {
		error_msg("Port must be above 1023");
		return -1;
	}

	len = strnlen(port,buffer);
	port[len-1] = '\0';

	return 0;
}

int get_ip(char ip_addr[],const int buffer) {
	
	int len = 0;            
	printf("Enter IP Address: ");
	if ( fgets(ip_addr,buffer,stdin) == NULL ) {
		return -1;
	}

	len = strnlen(ip_addr,buffer);
	ip_addr[len-1] = '\0';

	return 0;
}
