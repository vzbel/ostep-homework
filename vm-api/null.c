#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int *p = NULL;
  // Causes segmentation fault
  printf("%d", *p);
  return 0;
}