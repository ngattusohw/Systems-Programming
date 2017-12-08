/* I pledge my honor that I have abided by the Stevens Honor System
 * Daniel Salerno
 */

#ifndef _SOCKETTALK_H_
#define _SOCKETTALK_H_

#include "my.h"
#include "mylist.h"
#include <unistd.h>
#include <signal.h> 
#include <sys/types.h> /*pid_t*/
#include <stdio.h> /* perror */
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h> 
#include <netdb.h>
#include <sys/select.h>
#include <sys/time.h>

/* global vars */
#ifdef SERVER
struct client_pair {
	int fd;
	char *username;
};
struct s_node *gl_head; /* linked list */
fd_set gl_master; 
int gl_max_fd;
#else
#endif
/* functions */
#ifdef SERVER
struct client_pair *new_client_pair(int fd, char *username);
void send_message(int, char*);
char *process_message(int, char*);
#else
#endif


#endif
