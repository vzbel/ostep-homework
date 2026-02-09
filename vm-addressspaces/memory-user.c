#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MB_BYTES 1e6

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Include amount of memory to use\n");
    exit(0);
  }

  printf("pid: %d\n", getpid());
  // allocate the specified memory
  int num_mb = atoi(argv[1]);
  int arr_size = num_mb * MB_BYTES;
  int *arr = malloc(arr_size);

  printf("Enumerating array...\n");
  while (1)
  {
    for (int i = 0; i < arr_size / sizeof(int); i++)
    {
      arr[i] = i + 1;
    }
  }

  return 0;
}