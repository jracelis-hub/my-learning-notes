#include <stdio.h>
#include <netdb.h>

/* struct servent *getservent(void) 
   struct servent *getservbyname(const char *name, const char *proto);
   struct servent *getservbyport(int port, const char *proto);      */

int main() {
	
	/* When including a port it has to be host to network byte order htons() */
	const char *proto = "tcp";
	struct protoent *proto_name = getprotobyname(proto);
	const char *service = "ftp";
	struct servent *serv_name = getservbyname(service,proto_name->p_name);

	printf("%s: %d\n",serv_name->s_name,htons(serv_name->s_port));

	return 0;
}
