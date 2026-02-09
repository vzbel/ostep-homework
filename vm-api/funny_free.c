#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int *data = malloc(sizeof(int) * 100);
  free((data + 20));
  return 0;
}