#define PKGNAME "StackBased"
#define VERSION 0.1

int a, b, c, ind, con;
#include "functions.h"

int eval(stackT *dataStack, loopstack *loopStack, char cmd[]) {
  char msg[30];
  printf("cmd: %s\n", cmd);
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
	  loopStack->save = true;
    }

    else if (strcmp(cmd, "i") == 0) {
		StackPush(dataStack, loopStack->index);
    }

    else if (strcmp(cmd, "]") == 0) {
	  loopStack->index += 1;
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
        memset(loopStack->buffer, '\0', sizeof(loopStack->buffer) * RES_SIZE * DIM2);
        loopStack->bufsize = 0;
		loopStack->save = false;
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
  printf("Welcome to %s %.1f\n\n", PKGNAME, VERSION);
  stackT dataStack;
  loopstack loopStack;
  loopStack.bufsize = 0;
  loopStack.save = false;
  //TableInit();
  //int top = 0;
  StackInit(&dataStack, RES_SIZE);
  char cmd[DIM2];
  while(1) {
	  //printf("s>   ");
    scanf("%s", cmd);
    eval(&dataStack, &loopStack, cmd);
  }
}
