#include "stack.h"

/*

TODO:
	- Compound statements
	- Comments
	- File reading
	- While loop
	- More basic math

*/

typedef struct {
	const char *key;
	int value;
} item;

item cmdTable[] = {
	{"push",   12}, /* pushes number onto stack */
	{"pop",    1}, /* pops number from stack */
	{"+",      2}, /* adds top two numbers on stack */
	{"ifeq",   3}, /* checks if top element is bottom, jumps to <arg> */
	{"jump",   4}, /* jumps to <arg> */
	{"print",  5}, /* prints top element */
	{"dup",    6}, /* pushes copy of top element */
	{"dec",    7}, /* decrements top element */
	{"inc",    8}, /* increments top element */
	{"++",     9}, /* sums the elements in the stack */
	{"while", 10}, /* to be implemented */
	{"*",     11},
	{NULL,    -1}
};

int look(const char *key) {
	size_t i = 0;
	while (cmdTable[i].key != NULL) {
		if (strcmp(key, cmdTable[i].key) == 0) {
			return cmdTable[i].value;
		}
		else {
			i++;
		}
	}
	return -1;
}

double shell(char* cmd) {
	printf(">   ");
	int b;
	b = scanf("%s", cmd);
}

void error(char* msg) { printf("error: %s\n", msg); }

void stack(stackT *res, double frame) {
	if ((int) frame == res->top) {
		printf("stack[top] == %d\n", (int) res->contents[res->top]);	
	}
	else {
		printf("stack[%d] == %d\n", (int) frame, (int) res->contents[(int) frame]);
	}
}

void eval(stackT *res, char cmd[]) {
	return 1;
}

int main() {
	stackT res;
	StackInit(&res, RES_SIZE);
	char cmd[DIM2];
	while (1) {
		shell(cmd);
		//eval(&res, cmd, arg);
		//StackShow(&res);
		printf("\n");
	}
}
