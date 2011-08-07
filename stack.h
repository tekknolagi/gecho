#include "usefunc.h"

typedef struct {
  double *contents;
  int maxSize;
  int top;
} stackT;

void StackInit(stackT *stackP, int maxSize) {
  double *newContents;
  newContents = (double *)malloc(sizeof(double)*maxSize);
  if (newContents == NULL) {
    fprintf(stderr, "Not enough memory.\n");
    exit(1);
  }

  stackP->contents = newContents;
  stackP->maxSize = maxSize;
  stackP->top = -1;
}

void StackDestroy(stackT *stackP) {
  free(stackP->contents);
  stackP->contents = NULL;
  stackP->maxSize = 0;
  stackP->top = -1;
}

int StackIsEmpty(stackT *stackP) { return stackP->top < 0; }

int StackIsFull(stackT *stackP) { return stackP->top >= stackP->maxSize-1; }

void StackPush(stackT *stackP, double element) {
  if(StackIsFull(stackP)) {
    fprintf(stderr, "Can't push element: stack is full.\n");
    exit(1);
  }
  stackP->contents[++stackP->top] = element;
}

double StackPop(stackT *stackP) {
  if(StackIsEmpty(stackP)) {
    fprintf(stderr, "Can't pop element: stack is empty.\n");
    exit(1);
  }
  //printf("%.0f\n", stackP->contents[stackP->top-1]);
  return stackP->contents[stackP->top--];
}

void StackShow(stackT *stackP) {
  //printf("top: %d\n", stackP->top);
  if (stackP->top == -1) {
    printf("[ ]\n");
  }
  else if (stackP->top == 0) {
    printf("[ %d ]\n", (int) stackP->contents[0]);
  }
  else if (stackP->top > 0) {
    int i;
    printf("[ ");
    for (i = 0; i < stackP->top; i++) {
      printf("%d, ", (int) stackP->contents[i]);
    }
    printf("%d ]\n", (int) stackP->contents[stackP->top]);
  }
}
