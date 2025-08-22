#include <stdio.h>

/* getnameinfo()
   returns in human readable format:
   - port
   - IP address 
   What is needs:
   struct sockaddr addr (IPv4/IPv6 or either)
   sizeof sock addr
   char IP_ADDR[NI_MAXSERV]
   sizeof(IP_ADDR)
   char PORT[NI_MAX
   sizeof(PORT)
   0 (Can also manually set NI_NUMERICHOST or NI_NUMBERICSERV to be more clear)
*/

int main(int argc, char *argv[]) {

	struct sockaddr_storage client_both; /* Used to be able to hold IPv4 or IPv6 */
	struct sockaddr_in client_in; /* Used to hold only IPv4 */
	struct sockaddr_in6 client_in6; /* Used to hold only IPv6 */

	socklen_t client_len;

	/* Macros set */
	char host[NI_MAXHOST(1025)]; /* To hold IP address */
	socklen_t host_len = sizeof(host);

	char ser[NI_MAXSERV(32)]; /* To hold Port */
	sock_len_t ser_len = sizeof(ser);

	int flag = 0;

	/* To print out the host or service */
	printf("%s\n",host);
	printf("%s\n",ser);


	getnameinfo((struct sockaddr*)&client_both,sizeof(client_both),
	            host,sizeof(host),
				ser,sizeof(ser),
				0 );
	return 0;
}
