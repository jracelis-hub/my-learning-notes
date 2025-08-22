#include "networking.h"
#include <netinet/in.h>

int main(int argc, char *argv[]) {

	if ( argc == 1 ) {

		struct addrinfo hints, *server;
		struct sockaddr_in client;
		socklen_t client_len;
		char *host;
		socklen_t host_len;

		int sock_fd, client_fd;

		char port[16];
		char ip_addr[32];

		if ( get_port(port,16) == -1 ) {
			error_msg("Could not use port");
			return -1;
		}

		if ( get_ip(ip_addr,32) < 0 ) {
			error_msg("Could not use IPv4 address");
			return -1;
		}

		memset(&hints,0,sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;

		printf("Configuring server information...\n");
		if ( getaddrinfo(ip_addr,port,&hints,&server) < 0 ) {
			error_msg("Could not get address info");
			return -1;
		}

		sock_fd = socket(server->ai_family,server->ai_socktype,server->ai_protocol);
		if ( sock_fd < 0 ) {
			error_msg("Could not create a socket");
			freeaddrinfo(server);
			return -1;
		}

		if ( bind(sock_fd,server->ai_addr,server->ai_addrlen) < 0 ) {
			error_msg("Could not bind socket with port and address");
			close(sock_fd);
			freeaddrinfo(server);
			return -1;
		}
		
		printf("Configuration... DONE!\n\n\n");

		printf("Listening for incoming connections...\n");
		if ( listen(sock_fd,1) < 0 ) {
			error_msg("Could not list on port and address");
			close(sock_fd);
			freeaddrinfo(server);
			return -1;
		}

		client_len = sizeof(client);
		client_fd = accept(sock_fd,(struct sockaddr *)&client,&client_len);
		if ( client_fd < 0 ) {
			error_msg("Could not accept the connection");
			close(sock_fd);
			freeaddrinfo(server);
			return -1;
		}
		
		getnameinfo((struct sockaddr *)&client,client_len,host,host_len,0,0,NI_NUMERICHOST);
		printf("%s\n",host);
		
		/*
		while (1) {

		}
		*/
		close(sock_fd);
		freeaddrinfo(server);

		return 0;

	} else if ( argc == 2 && strcmp(argv[1],"help") == 0 ) {

		help();
		return 0;
	} else {
		help();
		return -1;
	}
}
