#include <stdio.h>
#include <stdlib.h>

#define VEC_SIZE 5

struct vector
{
  int *arr;
  int index;
  int maxSize;
};

struct vector make_vector()
{
  struct vector v;
  v.arr = (int *)calloc(VEC_SIZE, sizeof(int));
  v.index = 0;
  v.maxSize = VEC_SIZE;
  return v;
}

// print vector up to end index
void print_v(struct vector *v)
{
  printf("[");
  for (int i = 0; i < v->index; i++)
  {
    if (i == v->index - 1)
    {
      printf("%d", v->arr[i]);
    }
    else
    {
      printf("%d, ", v->arr[i]);
    }
  }
  printf("] i:%d, mS:%d \n", v->index, v->maxSize);
}

void insert_v(int item, struct vector *v)
{
  // increase size of v if full
  if (v->index >= v->maxSize)
  {
    v->arr = (int *)realloc(v->arr, v->maxSize * 2 * sizeof(int));
    v->maxSize *= 2;
  }

  // insert item
  v->arr[v->index] = item;
  (v->index)++;
}

int main(int argc, char *argv[])
{
  struct vector v = make_vector();
  for (int i = 0; i < v.maxSize; i++)
  {
    insert_v(i, &v);
  }
  print_v(&v);

  insert_v(5, &v);
  for (int i = v.index; i < v.maxSize; i++)
  {
    insert_v(i, &v);
  }
  insert_v(10, &v);
  print_v(&v);

  free(v.arr);
  return 0;
}