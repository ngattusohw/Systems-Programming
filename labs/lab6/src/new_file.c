#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void parent_stop(int sig) {fprintf(stderr, "They got back together!\n");}
void sig_usr_1(int sig) {fprintf(stderr, "Caught signal in CHILD.\n");}


int main(int argc, char **argv) {
	int pid = fork();
    if (pid!=0) {
        signal(SIGUSR1, &sig_usr_1);
        sleep(1000);
        exit(0);
    }
    signal(SIGTSTP, &parent_stop);
    sleep(1000);
    return 0;
}