double a, b, c, ind, con;
#include "functions.h"
#ifndef HEADER_H_
#define HEADER_H_
int cmds;

int which;

void next() {
  if (which < NUM_STACKS) which++;
  else which = 0;
}

void back() {
  if (which > 0) which--;
  else which = NUM_STACKS-1;
}



int main() {
stackT dataStack[NUM_STACKS];
stackT charStack;
//loopstack loopStack;
//loopStack.bufsize = 0;
//loopStack.save = false;
 for (cmds = 0; cmds < NUM_STACKS; cmds++)
   StackInit(&dataStack[NUM_STACKS], RES_SIZE);
StackInit(&charStack, RES_SIZE);
char cmd[DIM2] = "00";
cmds = 0;
char msg[30];

which = 0;

#endif
