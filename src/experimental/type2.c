#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  ptr(y, x) *((y *)(x))
#define ARRSIZE 3

int main() {

  void **arr = malloc(ARRSIZE*sizeof(void *));
  arr[0] = strdup("Some string!");

  printf("%s\n", (char *) arr[0]);

  arr[1] = malloc(sizeof(int));
  ptr(int, arr[1]) = 5;

  printf("%d\n", ptr(int, arr[1]));

  arr[2] = malloc(sizeof(double));
  ptr(double, arr[2]) = 27.3;

  printf("%f\n", ptr(double, arr[2]));

  int i;

  for (i = 0; i < ARRSIZE; i++)
    free(arr[i]);

  free(arr);

}
