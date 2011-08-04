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
	{"push",   0}, /* pushes number onto stack */
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

double shell(char* cmd, double arg) {
	printf(">   ");
	scanf("%s%*c", cmd);
	if (StringEqual(cmd, "push") || StringEqual(cmd, "jump") || StringEqual(cmd, "ifeq")) {
		scanf("%lf", &arg);
		return arg;
	}
	return 0;
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

void eval(stackT *res, char cmd[], double arg) {
	int a, b;
	switch(look(cmd)) {
		case 0: //push
			StackPush(res, arg);
			break;
		case 1: //pop
			StackPop(res);
			break;
		case 2: //add
			if (res->top <= 0) {
				error("not enough frames!");
			}
			else {
				b = StackPop(res);
				a = StackPop(res);
				StackPush(res, a+b);
			}
			break;
		case 3: //ifeq
		case 4: //jump
			if (res->top < (int) arg) {
				error("invalid frame!");
			}
			else {
				stack(res, arg);
			}
			break;
		case 5: //print
			if (StackIsEmpty(res)) {
				error("stack is empty!");
			}
			else {
				stack(res, res->top);
			}
			break;
		case 6: //dup
			if (StackIsEmpty(res)) {
				error("stack is empty!");
			}
			else {
				StackPush(res, res->contents[res->top]);
			}
			break;
		case 7: //dec
			if (StackIsEmpty(res)) {
				error("stack is empty!");
			}
			else {
				res->contents[res->top] -= 1;
			}
			break;
		case 8: //inc
			if (StackIsEmpty(res)) {
				error("stack is empty!");
			}
			else {
				res->contents[res->top] += 1;
			}
			break;
		case 9: //sum
			while (res->top != 0) {
				b = StackPop(res);
				a = StackPop(res);
				StackPush(res, a+b);
			}
			break;
			/*
		case 10: //while
			if (StackIsEmpty(&res)) {
				error("stack is empty!");
			}
			else {
				while ((a = res.contents[res.top]) != 0) {
					//do something with a... what?
				}
			}
			*/
		case 11:
			if (StackIsEmpty(res)) {
				error("stack is empty!");
			}
			else {
				b = StackPop(res);
				a = StackPop(res);
				StackPush(res, a*b);
			}
			break;
		default: //not found
			error("command not found!");
			break;
	}
}

int main() {
	stackT res;
	StackInit(&res, RES_SIZE);
	char cmd[DIM2]; double arg = 0;
	while (1) {
		arg = shell(cmd, arg);
		eval(&res, cmd, arg);
		StackShow(&res);
		printf("\n");
	}
}
