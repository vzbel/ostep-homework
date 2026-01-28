#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int x = 100;
  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    // child process
    x = 40;
    printf("child proc, x: %4d\n", x);
  }
  else
  {
    x = 10;
    printf("parent proc, x: %4d\n", x);
  }
  return 0;
}