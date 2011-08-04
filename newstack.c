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

void error(char* msg) { printf("error: %s\n", msg); }

void eval(stackT *res, char cmd[]) {
	int a, b, c;
	if (atoi(cmd)) {
		StackPush(res, atoi(cmd));
	}
	else {
		if (strcmp(cmd, "+") == 0) {
			b = StackPop(res);
			a = StackPop(res);
			StackPush(res, a+b);
		}
		else if (strcmp(cmd, "++") == 0) {
			while (res->top != 0) {
				b = StackPop(res);
				a = StackPop(res);
				StackPush(res, a+b);
			}
		}
		else if (strcmp(cmd, ".") == 0) {
			a = StackPop(res);
			printf(">  %d\n\n", a);
		}
	}
}

int main() {
	stackT res;
	StackInit(&res, RES_SIZE);
	char cmd[DIM2];
	while(cmd != "quit") {
		scanf("%s", cmd);
		eval(&res, cmd);
	}
}
