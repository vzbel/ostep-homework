#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void signalHandler(int sig)
{
    printf("goodbye!\n");
}

int main(int argc, char *argv[])
{
    int rc = fork();
    int pid = getpid();
    signal(SIGINT, signalHandler);
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child
        printf("hello\n");
        kill(pid, SIGINT);
    }
    return 0;
}