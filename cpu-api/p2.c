#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd = open("test.txt", O_CREAT | O_APPEND | O_WRONLY);
    if (fd == -1)
    {
        fprintf(stderr, "open file failed\n");
        exit(1);
    }

    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        int rc_write = write(fd, "\nhey1yep", 8);
        printf("child process\n");
    }
    else
    {
        // int rc_wait = wait(NULL);
        int rc_write = write(fd, "\nhey2", 5);
        printf("parent process\n");
    }
    return 0;
}