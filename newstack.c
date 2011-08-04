#include "stack.h"

/*

TODO:
	- Comments
	- File reading
	- While loop
	- More basic math

*/

item cmdTable[] = {
	//{"push",   12}, /* pushes number onto stack */
	//{"pop",    1}, /* pops number from stack */
	//{"+",      2}, /* adds top two numbers on stack */
	{"ifeq",   3}, /* checks if top element is bottom, jumps to <arg> */
	{"jump",   4}, /* jumps to <arg> */
	//{"print",  5}, /* prints top element */
	{"dup",    6}, /* pushes copy of top element */
	{"dec",    7}, /* decrements top element */
	{"inc",    8}, /* increments top element */
	//{"++",     9}, /* sums the elements in the stack */
	{"while", 10} /* to be implemented */
	//{"*",     11},
};

void error(char* msg) { printf("error: %s\n", msg); }

void eval(stackT *res, char cmd[]) {
	int a, b, c;
	if (atoi(cmd)) {
		StackPush(res, atoi(cmd));
	}
	else {
		if (strcmp(cmd, "+") == 0) {
			if (StackIsEmpty(res)) {
				error("stack is empty!");
			}
			else {
				b = StackPop(res);
				a = StackPop(res);
				StackPush(res, a+b);
			}
		}
		else if (strcmp(cmd, "++") == 0) {
			if (StackIsEmpty(res)) {
				error("stack is empty!");
			}
			else {
				while (res->top != 0) {
					b = StackPop(res);
					a = StackPop(res);
					StackPush(res, a+b);
				}
			}
		}
		else if (strcmp(cmd, ".") == 0) {
			if (StackIsEmpty(res)) {
				error("stack is empty!");
			}
			else {
				a = StackPop(res);
				printf(">  %d\n", a);
			}
		}
		else if (strcmp(cmd, "*") == 0) {
			if (StackIsEmpty(res)) {
				error("stack is empty!");
			}
			else {
				b = StackPop(res);
				a = StackPop(res);
				StackPush(res, a*b);
			}
		}
		else if (strcmp(cmd, "..") == 0) {
			if (StackIsEmpty(res)) {
				error("stack is empty!");
			}
			else {
				while (res->top != -1) {
					StackPop(res);
				}
			}
		}
		else if (strcmp(cmd, "shw") == 0) {
			printf(">  "); StackShow(res);
		}
	}
}

int main() {
	stackT res;
	StackInit(&res, RES_SIZE);
	char cmd[DIM2];
	while(1) {
		scanf("%s", cmd);
		eval(&res, cmd);
	}
}
