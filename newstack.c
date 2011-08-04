#include "stack.h"

/*

TODO:
	- Comments
	- File reading
	- While loop
	- More basic math

*/

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
		else if (strcmp(cmd, "**") == 0) {
		  if (StackIsEmpty(res)) {
		    error("stack is empty!");
		  }
		  else {
		    while (res->top != 0) {
		      b = StackPop(res);
		      a = StackPop(res);
		      StackPush(res, a*b);
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
		        a = StackPop(res)+1;
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
