#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFLEN 3

int main()
{
  // int fd = open("q2file.txt", O_APPEND | O_WRONLY);
  // if (fd == -1)
  // {
  //   fprintf(stderr, "open file failed: %s\n", strerror(errno));
  //   exit(1);
  // }
  // else
  // {
  //   int rc = fork();
  //   char buf[BUFLEN] = "hi";

  //   if (rc < 0)
  //   {
  //     fprintf(stderr, "fork failed\n");
  //     exit(1);
  //   }
  //   else if (rc == 0)
  //   {
  //     // child process
  //     int rc_write = write(fd, buf, sizeof(buf[0]) * (BUFLEN));
  //     if (rc_write == -1)
  //     {
  //       fprintf(stderr, "write failed (child)\n");
  //       exit(1);
  //     }
  //     else
  //     {
  //       printf("child process, fd:%d\n", fd);
  //     }
  //   }
  //   else
  //   {
  //     int rc_wait = wait(NULL);
  //     printf("parent process, fd:%d\n", fd);
  //   }
  //   return 0;
  // }
}