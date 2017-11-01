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

// void getOutPutFromServer(int sockfd, char* buffer){
	
// 	int n = read(sockfd,buffer,255);
// 	if (n < 0){
// 		error("ERROR reading from socket");
// 	}
// 	printf("%s\n",buffer);
// }

int main(int argc, char *argv[]){
	
	printf("%s\n", "HI!");
	return 0;
}
