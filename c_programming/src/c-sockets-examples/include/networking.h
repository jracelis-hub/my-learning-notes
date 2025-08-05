#ifndef           _NETWORKING_H
#define           _NETWORKING_H

#include              <stdio.h>
#include             <string.h>
#include         <sys/socket.h>
#include          <sys/types.h>
#include              <netdb.h>    
#include             <unistd.h>

void help(void);
void format(const int count, const char character);
void error_msg(const char *msg);
int get_port(char port[], const int buffer);
int get_ip(char ip_addr[], const int buffer);

#endif       /* _NETWORKING_H */
