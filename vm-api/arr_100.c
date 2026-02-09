#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int *data = malloc(sizeof(int) * 100);
  // We're accessing one beyond the last index of our array!
  data[100] = 0;
  return 0;
}