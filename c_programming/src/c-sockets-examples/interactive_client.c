#include "networking.h"

int main(int argc, char *argv[]) {

	char ip_addr[32];
	char port[16];

	struct addrinfo hints, *server;

	int sock_fd;
	
	if ( argc == 1 ) {

		if ( get_port(port,16) == -1 ) {
			error_msg("Could not get port");
			return -1;
		}

		if ( get_ip(ip_addr,32) == -1 ) {
			error_msg("Could not get ip address");
			return -1;
		}
		
		memset(&hints,0,sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;

		if ( getaddrinfo(ip_addr,port,&hints,&server) != 0 ) {
			error_msg("Could not set up address infomation");
			return -1;
		}

		sock_fd = socket(server->ai_family,server->ai_socktype,server->ai_protocol);
		if ( sock_fd == -1 ) {
			error_msg("Could not open a socket");
			freeaddrinfo(server);
			return -1;
		}

		printf("Attempting to connect to server...\n");

		if ( connect(sock_fd,server->ai_addr,server->ai_addrlen) == -1 ) {
			error_msg("Could not connect to server!");
			close(sock_fd);
			freeaddrinfo(server);
			return -1;
		}

		close(sock_fd);
		freeaddrinfo(server);

		return 0;
	} else if ( argc >= 2 && strcmp(argv[1],"help") == 0 ) {
		help();
		return 0;
	} else {
		help();
		return -1;
	}
}
