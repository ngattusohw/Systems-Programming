#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUF_SIZE 500

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char *argv[]){
	/*File descriptor stuff*/
	fd_set master;    // master file descriptor list
    fd_set read_fds;  // temp file descriptor list for select()
    int fdmax;        // maximum file descriptor number
    int newfd;
    char remoteIP[INET_ADDRSTRLEN];

    FD_ZERO(&master);    // clear the master and temp sets
    FD_ZERO(&read_fds);

    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int sfd, s;
    struct sockaddr_storage peer_addr;
    socklen_t peer_addr_len;
    ssize_t nread;
    char buf[BUF_SIZE];

   if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

   memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;    /* Allow IPv4 or IPv6 */
    hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
    hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
    hints.ai_protocol = 0;          /* Any protocol */
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;

   s = getaddrinfo(NULL, argv[1], &hints, &result);
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }

   /* getaddrinfo() returns a list of address structures.
       Try each address until we successfully bind(2).
       If socket(2) (or bind(2)) fails, we (close the socket
       and) try the next address. */

    int yes=1;

   for (rp = result; rp != NULL; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype,
                rp->ai_protocol);
        if (sfd == -1)
            continue;

       // lose the pesky "address already in use" error message
       setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

       if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
            break;                  /* Success */

       close(sfd);
    }

	if(rp == NULL) {               /* No address succeeded */
        fprintf(stderr, "Could not bind\n");
        exit(EXIT_FAILURE);
    }

	freeaddrinfo(result);           /* No longer needed */

    // add the listener to the master set
    FD_SET(sfd, &master);

    // keep track of the biggest file descriptor
    fdmax = sfd; // so far, it's this one


	/* Read datagrams and echo them back to sender */

	for (;;) {
		read_fds = master;
		if (select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(4);
        }

        // run through the existing connections looking for data to read
        for(int i = 0; i <= fdmax; i++) {
        	if (FD_ISSET(i, &read_fds)) { // we found a new one??
        		if(i == sfd){
        			//handle this new connection
        			printf("%s\n", "New connection");
        			peer_addr_len = sizeof(struct sockaddr_storage);
        			newfd = accept(sfd,(struct sockaddr *) &peer_addr,&peer_addr_len);
        			if(newfd == -1){
        				printf("%s\n", "I am here");
        				//perror("accept");
        			}else{
        				printf("%s\n", "In the else for a new connection");
                        FD_SET(newfd, &master); // add to master set
                        if (newfd > fdmax) {    // keep track of the max
                            fdmax = newfd;
                        }
                        printf("selectserver: new connection from %s on "
                            "socket %d\n",
                            inet_ntop(peer_addr.ss_family,
                                get_in_addr((struct sockaddr*)&peer_addr),
                                remoteIP, INET_ADDRSTRLEN),
                            newfd);
                    }
                }else{
                	//data from exisitng clients
                	printf("%s\n", "Old connection?");
                	peer_addr_len = sizeof(struct sockaddr_storage);
					nread = recvfrom(sfd, buf, BUF_SIZE, 0,
					        (struct sockaddr *) &peer_addr, &peer_addr_len);
					if (nread <=0){
						if(nread==0){
					    	printf("selectserver: socket %d hung up\n", i);
					    }else{
					    	perror("recv");
					    }
					    close(i);
					    FD_CLR(i, &master); // remove from master set
					}else{
						char host[NI_MAXHOST], service[NI_MAXSERV];

						s = getnameinfo((struct sockaddr *) &peer_addr,
				                peer_addr_len, host, NI_MAXHOST,
				                service, NI_MAXSERV, NI_NUMERICSERV);
						if (s == 0)
						    printf("Received %ld bytes from %s:%s Message::%s\n",
						            (long) nread, host, service,buf);
						else
						    fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));

						// if (sendto(sfd, buf, nread, 0,(struct sockaddr *) &peer_addr,
						//             peer_addr_len) != nread)
						//     fprintf(stderr, "Error sending response\n");
						//     
						//Now send the response to everyone
						for(int j = 0; j <= fdmax; j++) {
                            // send to everyone!
                            if (FD_ISSET(j, &master)) {
                                // except the listener and ourselves
                                if (j != sfd && j != i) {
                                    if (send(j, buf, nread, 0) == -1) {
                                        perror("send");
                                    }
                                }
                            }
                        }
					}
                }
        	}
		}//end of looping through connections
	}//end of forever loop
}


