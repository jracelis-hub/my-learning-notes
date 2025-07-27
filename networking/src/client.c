#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

	const char *port = "8080";		/* Open Port */
	const char *ip_addr = "127.0.0.1";	/* Local Host */
	int sock_fd,status;
	struct addrinfo hints,*host;
	const char *message = "Hello from client";
	const int buffer_size = 1024;
	char server_response[buffer_size];

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	printf("Generating socket infomation...\n");
	status = getaddrinfo(ip_addr,port,&hints,&host);
	if( status != 0 ) {
		printf("Could not proper set up host info\n");
		exit(1);
	}

	sock_fd = socket(host->ai_family,host->ai_socktype,host->ai_protocol);
	if( sock_fd == -1 ) {
		printf("Could not create socket\n");
		exit(1);
	}

	printf("Attempting to connect to host...\n");
	status = connect(sock_fd,host->ai_addr,host->ai_addrlen);
	if( status != 0 ) {
		printf("Could not connect to host!\n");
		exit(1);
	}

	status = send(sock_fd,message,strlen(message),0);
	if( status == -1 ) {
		printf("TCP Client\n");	
		exit(1);
	}

	status = recv(sock_fd,server_response,buffer_size,0);
		server_response[status] = '\0';
		printf("%s\n",server_response);

	freeaddrinfo(host);
	close(sock_fd);

	return 0;
}

