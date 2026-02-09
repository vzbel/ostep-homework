#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // allocate mem but forget to free
  int *p = malloc(sizeof(int));
  return 0;
}