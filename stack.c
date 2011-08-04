#include "stack.h"
#define VAR_SIZE 100

/*

TODO:
	- Comments
	- File reading
	- While loop
	- More basic math
	- Lookahead words...needed for function definitions
		-recursion

*/

typedef struct {
	const char *key;
	int value;
} variable;

variable Table[VAR_SIZE];

void TableInit() {
	Table[0].key = NULL;
	Table[0].value = 0;
}

int look(const char *key, int top) {
	size_t i = top;
	while (Table[i].key != NULL) {
		if (strcmp(key, Table[i].key) == 0) {
			return Table[i].value;
		}
		else {
			i--;
		}
	}
	return 0;
}

void error(char* msg) { printf("error: %s\n", msg); }

int eval(stackT *res, char cmd[], int top) {
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
		  if (a < b) {
			for (c = a; c <= b; c++) {
			  StackPush(res, c);
			}
		  }
		  else if (a > b) {
			for (c = a; c >= b; c--) {
			  StackPush(res, c);
			}
		  }
		  else if (a == b) {
			StackPush(res, a);
		  }
		}
		else if (strcmp(cmd, "drop") == 0) {
			printf("%d\n", StackPop(res));
		}
		else if (strcmp(cmd, "over") == 0) {
			a = res->contents[res->top - 1];
			StackPush(res, a);
		}
		//else if
		else {
			if (!(b = look(cmd, top))) {
				a = StackPop(res);
				top++;
				Table[top].key = cmd;
				Table[top].value = a;
			}
			else {
				StackPush(res, Table[b].value);
				//Table[b].key = cmd;
				//Table[b].value = a;
			}
			/*
			sprintf(msg, "%s - unknown command!", cmd);
			error(msg);
			*/
		}
		return top;
	}
}

int main() {
	stackT res;
	variable Table;
	TableInit();
	int top = 0;
	StackInit(&res, RES_SIZE);
	char cmd[DIM2];
	while(1) {
		scanf("%s", cmd);
		top = eval(&res, cmd, top);
	}
}
