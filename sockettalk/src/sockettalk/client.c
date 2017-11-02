#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 500

int main(int argc, char *argv[]){
	struct addrinfo hints;
    struct addrinfo *result, *rp;
    int sfd, s;
    size_t len;
    ssize_t nread;
    char buf[BUF_SIZE];
    char username[BUF_SIZE];

	if (argc < 3) {
	    fprintf(stderr, "Usage: %s host port msg\n", argv[0]);
	    exit(EXIT_FAILURE);
	}

	printf("%s", "Please enter a username::");
	scanf("%s",username); //need to make sure to do the realloc thing here

	/* Obtain address(es) matching host/port */

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;    /* Allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_STREAM; /* Datagram socket */
	hints.ai_flags = AI_PASSIVE;
	hints.ai_protocol = 0;          /* Any protocol */


	s = getaddrinfo(argv[1], argv[2], &hints, &result);
	if (s != 0) {
	    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
	    exit(EXIT_FAILURE);
	}

	/* getaddrinfo() returns a list of address structures.
	   Try each address until we successfully connect(2).
	   If socket(2) (or connect(2)) fails, we (close the socket
	   and) try the next address. */

	for (rp = result; rp != NULL; rp = rp->ai_next) {
	    sfd = socket(rp->ai_family, rp->ai_socktype,
	                 rp->ai_protocol);
	    if (sfd == -1)
	        continue;

	   if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1){
	   		printf("%s\n", "Connected!");
	        break;                  /* Success */
	   }

	   close(sfd);
	}

	if (rp == NULL) {               /* No address succeeded */
	    fprintf(stderr, "Could not connect\n");
	    exit(EXIT_FAILURE);
	}

	freeaddrinfo(result);           /* No longer needed */

	/* Send remaining command-line arguments as separate
	   datagrams, and read responses from server */

	//sending username to the server
	//First establish the new client to the server.. might not need this
	// if (write(sfd, " ", len) != len){
	//         fprintf(stderr, "partial/failed write\n");
	//         exit(EXIT_FAILURE);
	// }
	char slash[50];
	strcpy(slash,  "/nick ");
	strcat(slash, username);
	len = strlen(slash) + 1;

	if (write(sfd, slash, len) != len){
	        fprintf(stderr, "partial/failed write\n");
	        exit(EXIT_FAILURE);
	}

	//Do while loop here for the chat message stuff

	//MY CURRENT PROBLEM IS THAT THE CLIENT HAS TO LISTEN FOR MESSAGES FROM THE SERVER
	//WHILE ALSO LISTENING FOR NEW MESSAGES FROM THE USER


	char message_buff[500];
	for (;;) {
		scanf("%s",message_buff);
	    len = strlen(message_buff) + 1;
	            /* +1 for terminating null byte */

	   if (len + 1 > BUF_SIZE) {
	        fprintf(stderr,
	                "Ignoring long message in argument\n");
	        continue;
	    }

	   printf("SENDING :: %s\n", message_buff);
	   if (write(sfd, message_buff, len) != len) {
	        fprintf(stderr, "partial/failed write\n");
	        exit(EXIT_FAILURE);
	    }

	   nread = read(sfd, buf, BUF_SIZE);
	   printf("THIS IS NREAD %zd\n", nread);
	    if (nread == -1) {
	        perror("read");
	        exit(EXIT_FAILURE);
	    }

	   printf("Received %ld bytes: %s\n", (long) nread, buf);
	}

	exit(EXIT_SUCCESS);
}
