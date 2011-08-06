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
  int bufsize;
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
      if (dataStack->top < 1) {
	error("not enough frames!");
      }
      else {
	b = StackPop(dataStack);
	a = StackPop(dataStack);
	StackPush(dataStack, a+b);
      }
    }
    else if (strcmp(cmd, "++") == 0) {
      if (dataStack->top < 1) {
	error("not enough frames!");
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
      if (dataStack->top < 1) {
	error("not enough frames!");
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
	printf(">  %.0f\n", dataStack->contents[dataStack->top]);
      }
    }
    else if (strcmp(cmd, "*") == 0) {
      if (dataStack->top < 1) {
	error("not enough frames!");
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
      if (StackIsEmpty(dataStack)) {
	error("stack is empty!");
      }
      else {
	printf(">  "); StackShow(dataStack);
      }
    }
    else if (strcmp(cmd, "-") == 0) {
      if (dataStack->top < 1) {
	error("not enough frames!");
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
	  printf(">  %.0f\n", dataStack->contents[a]); // jumps to value of top integer
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
      printf(">   %.0f\n", StackPop(dataStack));
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
    else if (strcmp(cmd, "[") == 0) {
      /*

FIX ARRAY ACCESS BOUNDS CHECKING

      */
      if (dataStack->top < 1) {
	error("not enough frames!");
      }
      else {
	loopStack->index = (int) StackPop(dataStack);
	loopStack->control = (int) StackPop(dataStack);
	loopStack->save = true;
      }
    }
    else if (strcmp(cmd, "i") == 0) {
      StackPush(dataStack, loopStack->index);
    }
    else if (strcmp(cmd, "]") == 0) {
      loopStack->save = false;
      loopStack->index++;
      printf("ind %d\ncon %d\n", loopStack->index, loopStack->control);
      if (loopStack->index <= loopStack->control) {
	for (c = 0; c <= loopStack->bufsize; c++) {
	  printf("%s\n", loopStack->buffer[0]);
	  top = eval(dataStack, loopStack, (loopStack->buffer[c]), top);
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
      /*
	sprintf(msg, "%s - unknown command!", cmd);
	error(msg);
      */
    }
    return top;
    if(loopStack->save && (strcmp(cmd, "do") != 0)) {
      *loopStack->buffer[loopStack->bufsize++] = *cmd;
    }
  }
}

int main() {
  stackT dataStack;
  loopstack loopStack;
  loopStack.bufsize = 0;
  loopStack.save = false;
  TableInit();
  int top = 0;
  StackInit(&dataStack, RES_SIZE);
  char cmd[DIM2];
  while(1) {
    scanf("%s", cmd);
    top = eval(&dataStack, &loopStack, cmd, top);
  }
}
