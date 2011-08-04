#include "stack.h"

/*

TODO:
	- Comments
	- File reading
	- While loop
	- More basic math

*/

typedef struct {
	const char cmd[DIM2];
	int key;
} item;

item cmdTable[] = {
	//{"push",   12}, /* pushes number onto stack */
	//{"pop",    1}, /* pops number from stack */
	//{"+",      2}, /* adds top two numbers on stack */
	{"ifeq",   3}, /* checks if top element is bottom, jumps to <arg> */
	{"jump",   4}, /* jumps to <arg> */
	//{"print",  5}, /* prints top element */
	//{"dup",    6}, /* pushes copy of top element */
	//{"dec",    7}, /* decrements top element */
	//{"inc",    8}, /* increments top element */
	//{"++",     9}, /* sums the elements in the stack */
	{"while", 10} /* to be implemented */
	//{"*",     11},
};

void error(char* msg) { printf("error: %s\n", msg); }

void eval(stackT *res, char cmd[]) {
	int a, b, c;
	char msg[30];
	if ((cmd[0] >= '0') && (cmd[0] <= '9')) {
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
				//a = StackPop(res);
				printf(">  %d\n", (int) res->contents[res->top]);
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
		else if (strcmp(cmd, "show") == 0) {
			printf(">  "); StackShow(res);
		}
		else if (strcmp(cmd, "-") == 0) {
			if (StackIsEmpty(res)) {
				error("stack is empty!");
			}
			else {
				b = StackPop(res);
				a = StackPop(res);
				StackPush(res, a-b);
			}
		}
		else if (strcmp(cmd, "swap") == 0) {
			if (res->top < 1) {
				error("not enough frames!");
			}
			else {
				b = StackPop(res);
				a = StackPop(res);
				StackPush(res, b);
				StackPush(res, a);
			}
		}
		else if (strcmp(cmd, "dup") == 0) {
			if (StackIsEmpty(res)) {
				error("stack is empty!");
			}
			else {
				StackPush(res, res->contents[res->top]);
			}
		}
		else if(strcmp(cmd, "jump") == 0) {
			a = (int) res->contents[res->top];
			if (a > res->top) {
				error("not enough frames!");
			}
			else {
				printf(">  %d\n", (int) res->contents[a]); // jumps to value of top integer
			}
		}
		else if (strcmp(cmd, "range") == 0) {
		  b = StackPop(res);
		  a = StackPop(res);
		  if (a > b) {
		    for (c = b; c < a; c++) {
		      StackPush(res, c);
		    }
		  }
		  else if (b > a) {
		    for (c = a; c < b; c++) {
		      StackPush(res, c);
		    }
		  }
		  else if (a == b) {
		    StackPush(res, a);
		  }
		}
		else {
			sprintf(msg, "%s - unknown command!", cmd);
			error(msg);
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
