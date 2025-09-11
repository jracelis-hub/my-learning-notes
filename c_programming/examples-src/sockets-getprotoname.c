#include <stdio.h>
#include <netdb.h>

/* struct protoent *getprotoent(void);
   struct protoent *getprotobyname(const char *name);
   struct protent *getprotobynumber(int proto);    */

int main() {
	
	const char *proto = "tcp";

	struct protoent *proto_name = getprotobyname(proto);
	if (!proto_name) {
		fprintf(stderr,"Could not open file\n");
		return -1;
	}

	printf("%s: %d\n",proto_name->p_name,proto_name->p_proto);

	return 0;	
}
