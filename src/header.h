double a, b, c, ind, con;
#include "functions.h"
#ifndef HEADER_H_
#define HEADER_H_
int cmds;
int main() {
stackT dataStack;
stackT charStack;
//loopstack loopStack;
//loopStack.bufsize = 0;
//loopStack.save = false;
StackInit(&dataStack, RES_SIZE);
StackInit(&charStack, RES_SIZE);
char cmd[DIM2] = "00";
cmds = 0;
char msg[30];

#endif
