double a, b, c, ind, con;
#define MODETOP 3
#define PKGNAME "gecho"
#define VERSION 0.2
#include "functions.h"
int cmds;
int main() {
stackT dataStack;
//loopstack loopStack;
//loopStack.bufsize = 0;
//loopStack.save = false;
StackInit(&dataStack, RES_SIZE);
char cmd[DIM2] = "00";
cmds = 0;

