#include "stack.h"
#include "structs.h"
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
  for some reason only realizes first character of operator >> FIXXXX
  5 0 [ i show ]
  >  [ 0 ]
  error: s - unknown command!
  error: s - unknown command!
  error: s - unknown command!
  error: s - unknown command!
  error: s - unknown command!
  error: s - unknown command!

*/



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

int a, b, c, ind, con;

#include "functions.h"

int eval(stackT *dataStack, loopstack *loopStack, char cmd[]) {
  char msg[30];
  if ((cmd[0] >= '0') && (cmd[0] <= '9')) {
    StackPush(dataStack, atoi(cmd));
  }
  else {
    for(c = 0; c < strlen(cmd); c++) {
      cmd[c] = tolower(cmd[c]);
    }

    if (strcmp(cmd, "+") == 0) {
      plus(dataStack);
    }

    else if (strcmp(cmd, "++") == 0) {
      plusplus(dataStack);
    }

    else if (strcmp(cmd, "**") == 0) {
      mulmul(dataStack);
	  }

    else if (strcmp(cmd, ".") == 0) {
      showtop(dataStack);
    }

    else if (strcmp(cmd, "*") == 0) {
      mul(dataStack);
    }

    else if (strcmp(cmd, "..") == 0) {
      delstack(dataStack);
    }

    else if ((strcmp(cmd, "show") == 0)) {
      show(dataStack);
    }

    else if (strcmp(cmd, "-") == 0) {
      sub(dataStack);
    }

    else if (strcmp(cmd, "swap") == 0) {
      swap(dataStack);
    }

    else if (strcmp(cmd, "dup") == 0) {
      duplicate(dataStack, 0);
    }

    else if(strcmp(cmd, "jump") == 0) {
      jump(dataStack);
    }

    else if (strcmp(cmd, "range") == 0) {
      range(dataStack);
    }

    else if (strcmp(cmd, "drop") == 0) {
      drop(dataStack, true);
    }

    else if (strcmp(cmd, "over") == 0) {
      duplicate(dataStack, 1);
    }

    else if (strcmp(cmd, "wover") == 0) {
      duplicate(dataStack, 2);
    }

    else if (strcmp(cmd, "top") == 0) {
      StackPush(dataStack, dataStack->top);
    }

    else if (strcmp(cmd, "outascii") == 0) {
      outascii(dataStack);
    }

    else if (strcmp(cmd, "allascii") == 0) {
      allascii(dataStack);
    }

    else if (strcmp(cmd, "/") == 0) {
      divide(dataStack);
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
      //printf("command: %s\n", cmd);
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
          //printf("%s\n", loopStack->buffer);
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
      //printf("cmd: %s\n", cmd);
      //printf("ptr: %d\n", *cmd);
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
