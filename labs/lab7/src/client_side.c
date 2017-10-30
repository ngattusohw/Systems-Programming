#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>

void error(char *msg){
	perror(msg);
	exit(0);
}

void getOutPutFromServer(int sockfd, char* buffer){
	
	int n = read(sockfd,buffer,255);
	if (n < 0){
		error("ERROR reading from socket");
	}
	printf("%s\n",buffer);
}

int main(int argc, char *argv[]){
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[256];
	if (argc < 3){
		fprintf(stderr,"usage %s hostname port message", argv[0]);
		exit(0);
	}
	portno = atoi(argv[2]);
	//portno = 3000;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	if (sockfd < 0){
		error("err opening socket");
	}else{
		server = gethostbyname(argv[1]);
		if (server == NULL){
			fprintf(stderr,"err, no host");
			exit(0);
		}

		bzero((char *) &serv_addr, sizeof(serv_addr));
		serv_addr.sin_family = AF_INET;
		bcopy((char *)server->h_addr,
			(char *)&serv_addr.sin_addr.s_addr,
			server->h_length);
		serv_addr.sin_port = htons(portno);

		if (connect(sockfd,&serv_addr,sizeof(serv_addr)) < 0){
			error("err connecting");
		}else{
			printf("%s\n", "Connected!");
			n = write(sockfd,argv[3],strlen(argv[3]));
			if (n < 0){
				error("err writing");
			}else{
				printf("%s\n", "Completed!");
				
				bzero(buffer,256);
				n = read(sockfd,buffer,255);
				if (n < 0){
					error("ERROR reading from socket");
				}
				printf("%s\n",buffer);

				bzero(buffer,256);
				int m = read(sockfd,buffer,255);
				if (m < 0){
					error("ERROR reading from socket");
				}
				printf("%s\n",buffer);


				//getOutPutFromServer(sockfd,buffer);

			}

		}
	}
	return 0;
}
