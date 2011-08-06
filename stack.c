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

typedef enum {
  false, true
} bool;

typedef struct {
  const char *key;
  int value;
} variable;

typedef struct {
  int index;
  int control;
  size_t bufsize;
  char buffer[RES_SIZE][DIM2];
  bool save;
} loopstack;

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

int eval(stackT *dataStack, loopstack *loopStack, char cmd[], int top) {
  int a, b, c, ind, con;
  char msg[30];
  if ((cmd[0] >= '0') && (cmd[0] <= '9')) {
    StackPush(dataStack, atoi(cmd));
  }
  else {
    for(c = 0; c < strlen(cmd); c++) {
      cmd[c] = tolower(cmd[c]);
    }
    if (strcmp(cmd, "+") == 0) {
      if (StackIsEmpty(dataStack)) {
	error("stack is empty!");
      }
      else {
	b = StackPop(dataStack);
	a = StackPop(dataStack);
	StackPush(dataStack, a+b);
      }
    }
    else if (strcmp(cmd, "++") == 0) {
      if (StackIsEmpty(dataStack)) {
	error("stack is empty!");
      }
      else {
	while (dataStack->top != 0) {
	  b = StackPop(dataStack);
	  a = StackPop(dataStack);
	  StackPush(dataStack, a+b);
	}
      }
    }
    else if (strcmp(cmd, "**") == 0) {
      if (StackIsEmpty(dataStack)) {
	error("stack is empty!");
      }
      else {
	while (dataStack->top != 0) {
	  b = StackPop(dataStack);
	  a = StackPop(dataStack);
	  StackPush(dataStack, a*b);
	}
      }
    }
    else if (strcmp(cmd, ".") == 0) {
      if (StackIsEmpty(dataStack)) {
	error("stack is empty!");
      }
      else {
	//a = StackPop(dataStack);
	printf(">  %d\n", (int) dataStack->contents[dataStack->top]);
      }
    }
    else if (strcmp(cmd, "*") == 0) {
      if (StackIsEmpty(dataStack)) {
	error("stack is empty!");
      }
      else {
	b = StackPop(dataStack);
	a = StackPop(dataStack);
	StackPush(dataStack, a*b);
      }
    }
    else if (strcmp(cmd, "..") == 0) {
      if (StackIsEmpty(dataStack)) {
	error("stack is empty!");
      }
      else {
	while (dataStack->top != -1) {
	  StackPop(dataStack);
	}
      }
    }
    else if (strcmp(cmd, "show") == 0) {
      printf(">  "); StackShow(dataStack);
    }
    else if (strcmp(cmd, "-") == 0) {
      if (StackIsEmpty(dataStack)) {
	error("stack is empty!");
      }
      else {
	b = StackPop(dataStack);
	a = StackPop(dataStack);
	StackPush(dataStack, a-b);
      }
    }
    else if (strcmp(cmd, "swap") == 0) {
      if (dataStack->top < 1) {
	error("not enough frames!");
      }
      else {
	b = StackPop(dataStack);
	a = StackPop(dataStack);
	StackPush(dataStack, b);
	StackPush(dataStack, a);
      }
    }
    else if (strcmp(cmd, "dup") == 0) {
      if (StackIsEmpty(dataStack)) {
	error("stack is empty!");
      }
      else {
	StackPush(dataStack, dataStack->contents[dataStack->top]);
      }
    }
    else if(strcmp(cmd, "jump") == 0) {
      a = StackPop(dataStack)+1;
      if (a > dataStack->top) {
	error("not enough frames!");
      }
      else {
	printf(">  %d\n", (int) dataStack->contents[a]); // jumps to value of top integer
      }
    }
    else if (strcmp(cmd, "range") == 0) {
      b = StackPop(dataStack);
      a = StackPop(dataStack);
      if (a < b) {
	for (c = a; c <= b; c++) {
	  StackPush(dataStack, c);
	}
      }
      else if (a > b) {
	for (c = a; c >= b; c--) {
	  StackPush(dataStack, c);
	}
      }
      else if (a == b) {
	StackPush(dataStack, a);
      }
    }
    else if (strcmp(cmd, "drop") == 0) {
      printf("%d\n", (int) StackPop(dataStack));
    }
    else if (strcmp(cmd, "over") == 0) {
      a = dataStack->contents[dataStack->top - 1];
      StackPush(dataStack, a);
    }
    else if (strcmp(cmd, "wover") == 0) {
      a = dataStack->contents[dataStack->top - 2];
      StackPush(dataStack, a);
    }
    else if (strcmp(cmd, "do") == 0) {
      loopStack->index = StackPop(dataStack);
      loopStack->control = StackPop(dataStack);
      loopStack->save = true;
    }
    else if (strcmp(cmd, "i") == 0) {
      StackPush(dataStack, loopStack->index);
    }
    else if (strcmp(cmd, "loop")) {
      loopStack->index++;
      if (loopStack->index < loopStack->control) {
	for (c = 0; c <= loopStack->bufsize; c++) {
	  top = eval(dataStack, loopStack, loopStack->buffer[c], top);
	}
      }
      else {
	loopStack->index = 0;
	loopStack->control = 0;
	memset( (void *) loopStack->buffer, '\0', sizeof(loopStack->buffer) * RES_SIZE * DIM2);
	loopStack->bufsize = 0;
	loopStack->save = 0;
      }
    }
    /*
      else if (strcmp(cmd, "while") == 0) {
      a = 
      }
    */
    // LOOK AHEAD WORD
    else {
      if (!(b = look(cmd, top))) {
	a = StackPop(dataStack);
	top++;
	Table[top].key = cmd;
	Table[top].value = a;
      }
      else {
	StackPush(dataStack, Table[b].value);
	//Table[b].key = cmd;
	//Table[b].value = a;
      }
      /*
	sprintf(msg, "%s - unknown command!", cmd);
	error(msg);
      */
    }
    return top;
    if(loopStack->save && (strcmp(cmd, "do") != 0) && (strcmp(cmd, "loop") != 0)) {
      *loopStack->buffer[loopStack->bufsize++] = *cmd;
    }
  }
}

int main() {
  stackT dataStack;
  variable Table;
  loopstack loopStack;
  loopStack.bufsize = 0;
  TableInit();
  int top = 0;
  StackInit(&dataStack, RES_SIZE);
  char cmd[DIM2];
  while(1) {
    scanf("%s", cmd);
    top = eval(&dataStack, &loopStack, cmd, top);
  }
}
