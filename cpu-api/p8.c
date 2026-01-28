#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int p[2];
    int rc_pipe = pipe(p);
    if (rc_pipe < 0)
    {
        exit(1);
    }

    int rc_fork = fork();
    if (rc_fork < 0)
    {
        exit(1);
    }
    else if (rc_fork == 0)
    {
        // child process writes through pipe, so close output
        close(p[0]);
        write(p[1], "hey", 4);
    }
    else
    {
        // parent reads, so close input
        close(p[1]);
        char rbuf[20];
        int nbytes = read(p[0], rbuf, sizeof(rbuf));
        printf("received %s\n", rbuf);
    }
}