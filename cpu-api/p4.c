#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child
        char *argv[3];
        argv[0] = "ls";
        argv[1] = "./";
        argv[2] = NULL;

        // execl("/bin/ls", "ls", "./", NULL);

        // char *envp[1];
        // envp[0] = "hey";
        // execle("/bin/ls", "ls", "./", NULL, envp);

        // execlp("ls", "ls", "./", NULL);

        // execv("/bin/ls", argv);

        // execvp("/bin/ls", argv);

        char *envp[1];
        envp[0] = "hey";
        execvpe("ls", argv, envp);
    }
    else
    {
        // parent
    }
    return 0;
}