#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define NUM_READS 2
#define BUF_SIZE 1000

double convert_tval(struct timeval *t)
{
  return (double)t->tv_sec + (double)(t->tv_usec / 1e6);
}

void do_switch()
{
  // Perform multiple 0-byte reads
  char buf[BUF_SIZE];
  struct timeval t1, t2;
  gettimeofday(&t1, NULL);
  // for (int i = 0; i < NUM_READS; i++)
  // {
  read(STDIN_FILENO, buf, 0);
  // }
  gettimeofday(&t2, NULL);

  printf("%lf\n", (convert_tval(&t2) - convert_tval(&t1)));
}

int main(int argc, char *argv[])
{
  // do_switch();
  return 0;
}