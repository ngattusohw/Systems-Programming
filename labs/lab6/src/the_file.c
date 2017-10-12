// #include <signal.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>

// void sighandler(int);

// int main () {
//    signal(SIGINT, sighandler);

//    while(1) {
//       printf("Going to sleep for a second...\n");
//       sleep(1); 
//    }
//    return(0);
// }

// void sighandler(int signum) {
//    printf("Caught signal %d, coming out...\n", signum);
//    //exit(1);
// }
// 
// 
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sighup(int); /* routines child will call upon sigtrap */
void sigint(int);
void sigquit(int);

int main(void) {

    int pid;

    signal(SIGHUP,sighup); /* set function calls */
    signal(SIGINT,sigint);
    signal(SIGQUIT, sigquit);

    /* get child process */
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {

        /* child */
        for(;;); /* loop for ever */

    } else {

        signal(SIGHUP, SIG_DFL);
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);

        /* parent */
        /* pid hold id of child */
        printf("\nPARENT: sending SIGHUP\n\n");
        kill(pid,SIGHUP);
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT: sending SIGINT\n\n");
        kill(pid,SIGINT);
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT: sending SIGQUIT\n\n");
        kill(pid,SIGQUIT);
        sleep(3);
    }

    return 0;
}

void sighup(int signo) {
    signal(SIGHUP,sighup); /* reset signal */
    printf("CHILD: I have received a SIGHUP\n");
}

void sigint(int signo) {
    signal(SIGINT,sigint); /* reset signal */
    printf("CHILD: I have received a SIGINT\n");
}

void sigquit(int signo) {
    printf("My DADDY has Killed me!!!\n");
    exit(0);
}
