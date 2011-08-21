#include "structs.h"

//Stack struct.
typedef struct {
	double *contents;
	int maxSize;
	int top;
} stackT;

//Initializes the stack, checking for enough memory.
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

//Destroys the stack and frees the allocated memory.
void StackDestroy(stackT *stackP) {
	free(stackP->contents);
	stackP->contents = NULL;
	stackP->maxSize = 0;
	stackP->top = -1;
}

//Checks if the stack is empty.
int StackIsEmpty(stackT *stackP) {
	return stackP->top < 0;
}

//Checks if the stack is full.
int StackIsFull(stackT *stackP) {
	return stackP->top >= stackP->maxSize-1;
}

//Pushes a number onto the stack.
void StackPush(stackT *stackP, double element) {
	if(StackIsFull(stackP)) {
		fprintf(stderr, "Can't push element: stack is full.\n");
		exit(1);
	}
	stackP->contents[++stackP->top] = element;
}

//Pops a number from the stack.
double StackPop(stackT *stackP) {
	if(StackIsEmpty(stackP)) {
		fprintf(stderr, "Can't pop element: stack is empty.\n");
		exit(1);
	}
	return stackP->contents[stackP->top--];
}

//Pretty-prints the stack.
void StackShow(stackT *stackP) {
	if (stackP->top == -1) {
		printf("[ ]\n");
	}
	else if (stackP->top == 0) {
		printf("[ %.0f ]\n", stackP->contents[0]);
	}
	else if (stackP->top > 0) {
		int i;
		printf("[ ");
		for (i = 0; i < stackP->top; i++) {
			printf("%.0f, ", stackP->contents[i]);
		}
		printf("%.0f ]\n", stackP->contents[stackP->top]);
	}
}
