#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER 1024

/* To have TCP Server the following requirements are needed:
 * getaddrinfo()
 * socket()
 * bind()
 * listen()
 * accept()
 * recv() and send()
 * close()
*/ 

int main(int argc, char **argv) {

	const char *ip_addr = "127.0.0.1";		/* Local address */
	const char *port = "8080";		/* Open port */
	int status,server_fd,client_fd;
	struct addrinfo hints,*server;
	struct sockaddr client;
	socklen_t client_len;
	const char *http_response = 
				"HTTP/1.1 200 OK\r\n"
				"Connection: close\r\n"
				"Content-Type: text/html\r\n\r\n"
				"<h1>Hello from your server!</h1>";
	char message[BUFFER];

	/* Make sure the hints struct is intialized to zero */	
	memset(&hints,0,sizeof(struct addrinfo));

	/* Set up server information */
	hints.ai_family = AF_INET;		/* IPv4 address family */
	hints.ai_socktype = SOCK_STREAM;		/* TCP */
	hints.ai_flags = 0;
	hints.ai_protocol = 0;	/* The protocol IPPROTO_TCP (6) does not need to be expilicty said because ai_socktype handles this */

	status = getaddrinfo(ip_addr,port,&hints,&server);
	printf("Setting up server information...\n");
	if(status != 0) {
		printf("Could not get address info.\n");
		exit(1);
	}

	server_fd = socket(server->ai_family,server->ai_socktype,server->ai_protocol);
	printf("Setting up socket...\n");
	if(server_fd == -1) {
		printf("Could not open a socket.\n");
		exit(1);
	}
	
	/* Binds the server socket with the address and address length */
	printf("Binded socket to address and port...\n");
	status = bind(server_fd,server->ai_addr,server->ai_addrlen);
	if(status == -1) {
		printf("Could not bind to socket.\n");
		exit(1);
	}

	status = listen(server_fd,1);		/* Only listens for 1 incoming device */
	printf("Waiting for incoming connections...\n");
	if(status == -1) {
		printf("Could not grab any incoming connections.\n");
		exit(1);
	}

	printf("Connected...\n");
	client_len = sizeof(client);
	client_fd = accept(server_fd,&client,&client_len);
	if(client_fd == -1) {
		printf("Could not accept request.\n");
		exit(1);
	}

	status = recv(client_fd,message,BUFFER,0);
	if( status>0 ) {
		printf("Received %d bytes:\n---\n",status);	
		for(int i=0; i<status; i++) {
			putchar(message[i]);
		}
	}

	status = send(client_fd,http_response,strlen(http_response),0);
	if( status<1 ) {
		printf("Could not send data.\n");
		exit(1);
	}
	printf("Send %d bytes\n",status);

	close(client_fd);
	freeaddrinfo(server);	
	return 0;
}
