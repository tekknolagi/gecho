#include "stack.h"
#define VAR_SIZE 100

/*

  TODO:
  - Comments
  - File reading
  - More basic math
  - Lookahead words...needed for function definitions
  - recursion
  - weird loop issue:
  5 1 [ i * show ]
  >  [ 1 ]
  >  [ 2 ]
  >  [ 6 ]
  >  [ 24 ]
  >  [ 120 ]
  >  [ 120 ]
  >  [ 120 ]
  >  [ 120 ]
  >  [ 120 ]
  >  [ 120 ]
  >  [ 120 ]
  >  [ 120 ]
  >  [ 120 ]
  >  [ 120 ]
  >  [ 120 ]
  >  [ 120 ]
  - another weird loop issue:
  for some reason only realizes first character of operator
  5 0 [ i show ]
  >  [ 0 ]
  error: s - unknown command!
  error: s - unknown command!
  error: s - unknown command!
  error: s - unknown command!
  error: s - unknown command!
  error: s - unknown command!

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
  int bufsize;
  char buffer[RES_SIZE][DIM2];
  bool save;
} loopstack;

/*
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
*/

void error(char* msg) { printf("error: %s\n", msg); }

int eval(stackT *dataStack, loopstack *loopStack, char cmd[]) {
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
      if (dataStack->top < 1) {
	//error("not enough frames!");
	StackPush(dataStack, 0);
	eval(dataStack, loopStack, cmd);
      }
      else {
	b = StackPop(dataStack);
	a = StackPop(dataStack);
	StackPush(dataStack, a+b);
      }
    }
    else if (strcmp(cmd, "++") == 0) {
      if (dataStack->top < 1) {
	StackPush(dataStack, 0);
	//error("not enough frames!");
	eval(dataStack, loopStack, cmd);
      }
      else {
	while (dataStack->top >= 1) {
	  b = StackPop(dataStack);
	  a = StackPop(dataStack);
	  StackPush(dataStack, a+b);
	}
      }
    }
    else if (strcmp(cmd, "**") == 0) {
      if (dataStack->top < 1) {
	//error("not enough frames!");
	StackPush(dataStack, 1);
	eval(dataStack, loopStack, cmd);
      }
      else {
	while (dataStack->top >= 1) {
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
	printf(">  %f\n", dataStack->contents[dataStack->top]);
      }
    }
    else if (strcmp(cmd, "*") == 0) {
      if (dataStack->top < 1) {
	//error("not enough frames!");
	StackPush(dataStack, 1);
	eval(dataStack, loopStack, cmd);
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
	while (dataStack->top > -1) {
	  StackPop(dataStack);
	}
      }
    }
    else if ((strcmp(cmd, "show") == 0)) {// || (strcmp(cmd, "s") == 0)) {
      //if (StackIsEmpty(dataStack)) {
      //error("stack is empty!");
      //}
      //else {
      printf(">  "); StackShow(dataStack);
      //}
    }
    else if (strcmp(cmd, "-") == 0) {
      if (dataStack->top < 1) {
	//error("not enough frames!");
	StackPush(dataStack, 0);
	eval(dataStack, loopStack, cmd);
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
      if (StackIsEmpty(dataStack)) {
	error("stack is empty!");
      }
      else {
	a = StackPop(dataStack)+1;
	if (a > dataStack->top) {
	  error("not enough frames!");
	}
	else {
	  printf(">  %f\n", dataStack->contents[a]); // jumps to value of top integer
	}
      }
    }
    else if (strcmp(cmd, "range") == 0) {
      if (dataStack->top < 1) {
	error("not enough frames!");
      }
      else {
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
    }
    else if (strcmp(cmd, "drop") == 0) {
      if (StackIsEmpty(dataStack)) {
	error("stack is empty!");
      }
      else {
	printf(">   %f\n", StackPop(dataStack));
      }
    }
    else if (strcmp(cmd, "over") == 0) {
      if (dataStack->top < 1) {
	error("not enough frames!");
      }
      else {
	a = dataStack->contents[dataStack->top - 1];
	StackPush(dataStack, a);
      }
    }
    else if (strcmp(cmd, "wover") == 0) {
      if (dataStack->top < 2) {
	error("not enough frames!");
      }
      else {
	a = dataStack->contents[dataStack->top - 2];
	StackPush(dataStack, a);
      }
    }
    else if (strcmp(cmd, "top") == 0) {
      StackPush(dataStack, dataStack->top);
    }
    else if (strcmp(cmd, "outascii") == 0) {
      if (StackIsEmpty(dataStack)) {
	error("stack is empty!");
      }
      else {
	printf(">   %c\n", (unsigned char) StackPop(dataStack));
      }
    }
    else if (strcmp(cmd, "/") == 0) {
      if (dataStack->top < 1) {
	StackPush(dataStack, 1);
	eval(dataStack, loopStack, "swap");
      }
      else {
	b = StackPop(dataStack);
	a = StackPop(dataStack);
	StackPush(dataStack, (double) a/b);
      }
    }
    else if (strcmp(cmd, "[") == 0) {
      if (dataStack->top < 1) {
	error("not enough frames!");
      }
      else {
	loopStack->index = (int) StackPop(dataStack);
	loopStack->control = (int) StackPop(dataStack) + 1;
      }
    }
    else if (strcmp(cmd, "i") == 0) {
      if (loopStack->index < loopStack->control) {
	StackPush(dataStack, loopStack->index++);
	loopStack->save = true;
      }
      else {
	loopStack->save = false;
      }
    }
    else if (strcmp(cmd, "]") == 0) {
      loopStack->save = false;
      //printf("ind %d\ncon %d\n", loopStack->index, loopStack->control);
      if (loopStack->index < loopStack->control) {
	for (c = 0; c < loopStack->bufsize; c++) {
	  printf("%s\n", loopStack->buffer[c]);
	  eval(dataStack, loopStack, loopStack->buffer[c]);
	}
      }
      else {
	loopStack->index = 0;
	loopStack->control = 0;
	memset( (void *) loopStack->buffer, '\0', sizeof(loopStack->buffer) * RES_SIZE * DIM2);
	loopStack->bufsize = 0;
      }
    }
    else {
      /*
	if (!(b = look(cmd, top))) {
	if (!StackIsEmpty(dataStack)) {
	a = StackPop(dataStack);
	if (top+1 < VAR_SIZE) {
	top++;
	Table[top].key = cmd;
	Table[top].value = a;
	}
	else {
	error("var stack full!");
	}
	}
	}
	else {
	if (b <= top) {
	StackPush(dataStack, Table[b].value);
	}
	else {
	error("var does not exist!");
	}
	//Table[b].key = cmd;
	//Table[b].value = a;
	}
      */
      sprintf(msg, "%s - unknown command!", cmd);
      error(msg);
    }
    if (loopStack->save) {
      *loopStack->buffer[loopStack->bufsize++] = *cmd;
    }
    //return top;
  }
}

int main() {
  stackT dataStack;
  loopstack loopStack;
  loopStack.bufsize = 0;
  loopStack.save = false;
  //TableInit();
  //int top = 0;
  StackInit(&dataStack, RES_SIZE);
  char cmd[DIM2];
  while(1) {
    scanf("%s", cmd);
    eval(&dataStack, &loopStack, cmd);
  }
}
