double a, b, c, ind, con;
int var_index;
#define PKGNAME "gecho"
#define VERSION 0.5
#include "functions.h"
int cmds;
int top;
double variables[RES_SIZE];

//This is the eval function.
void eval(stackT *dataStack, loopstack *loopStack, mode list[MODETOP], char cmd[], FILE *toc, const_list cons[CONSTOP]) {
  //Checks if the first digit is a number, and if so, pushes it.
  if ((cmd[0] == '-') && (isdigit(cmd[1]) || cmd[1] == '.')) {
    fprintf(toc, "StackPush(&dataStack, %f);\n", atof(cmd));
  }
  else if (isdigit(cmd[0]) || ((cmd[0] == '.') && isdigit(cmd[1]))) {
    fprintf(toc, "StackPush(&dataStack, %f);\n", atof(cmd));
  }
  else if (!strcmp(cmd, "<>")) {
    fprintf(toc, "StackPush(&charStack, (int) \' \');\n");
  }
  else if ((cmd[0] == '\'') || (cmd[0] == '`')) {
    if (strlen(cmd) > 1) {
      for (a = 1; a < strlen(cmd); a++) {
	fprintf(toc, "StackPush(&charStack, (int) \'%c\');\n", cmd[(int) a]);
      }
    }
    else {
      fprintf(toc, "error(\"not a valid char/string!\");\n");
    }
  }
  else {
    //Converts the command to all lowercase.
    for(c = 0; c < strlen(cmd); c++) {
      cmd[(int) c] = tolower(cmd[(int) c]);
    }

    if (!strcmp(cmd, "nil"));

    //If it's a mode change...toggle it.
    else if ((cmd[0] == '@') && (strlen(cmd) > 1)) {
      a = toggle(list, lookup(list, cmd));
      if (a) {
	fprintf(toc, "printf(\"--%s %s--\\n\");\n", cmd, is_enabled(list,cmd)?"ON":"OFF");
      }
    }

    else if (cmd[0] == '#') {
      if (strlen(cmd) > 1) {
	if (c_lookup(cons, cmd) != -1) {
	  fprintf(toc, "StackPush(dataStack, cons[c_lookup(cons, cmd)].value);\n");
	}
      }
      else {
	fprintf(toc, "error(\"not enough frames!\");\n");
      }
    }

    else if (!strcmp(cmd, "and")) {
      log_and(dataStack);
    }

    else if (!strcmp(cmd, "or")) {
      log_or(dataStack);
    }

    else if ((cmd[0] == '!') && (strlen(cmd) > 1) && (cmd[1] >= '-') && (cmd[1] <= '9')) {
      var_index = atoi(cmd+1);
      if (dataStack->top >= 0) {
	variables[var_index] = StackPop(dataStack);
      }
      else {
	fprintf(toc, "error(\"stack is empty!\")\n;");
      }
    }

    else if ((cmd[0] == '&') && (strlen(cmd) > 1) && (cmd[1] >= '-') && (cmd[1] <= '9')) {
      var_index = atoi(cmd+1);
      //printf("ind: %d\n", var_index);
      fprintf(toc, "StackPush(&dataStack, %f);\n", variables[var_index]);
    }

    else if (!strcmp(cmd, "pow")) {
      fprintf(toc, "powers(&dataStack);\n");
    }

    else if (!strcmp(cmd, "mod")) {
      fprintf(toc, "modulus(&dataStack);");
    }

    else if (!strcmp(cmd, "pi")) {
      fprintf(toc, "StackPush(&dataStack, %f);\n", M_PI);
    }

    else if (!strcmp(cmd, "tan")) {
      fprintf(toc, "tangent(&dataStack);\n");
    }

    else if (!strcmp(cmd, "sin")) {
      fprintf(toc, "sine(&dataStack);\n");
    }

    else if (!strcmp(cmd, "cos")) {
      fprintf(toc, "cosine(&dataStack);\n");
    }

    else if (!strcmp(cmd, "read")) {
      fprintf(toc, "userin(&dataStack);\n");
    }

    else if (!strcmp(cmd, ">")) {
      fprintf(toc, "gt(&dataStack);\n");
    }

    else if (!strcmp(cmd, "<")) {
      fprintf(toc, "lt(&dataStack);\n");
    }

    else if (!strcmp(cmd, "=")) {
      fprintf(toc, "eqeq(&dataStack);\n");
    }

    else if (!strcmp(cmd, "<=")) {
      fprintf(toc, "lteq(&dataStack);\n");
    }

    else if (!strcmp(cmd, ">=")) {
      fprintf(toc, "gteq(&dataStack);\n");
    }

    else if (!strcmp(cmd, "+")) {
      fprintf(toc, "plus(&dataStack);\n");
    }

    else if (!strcmp(cmd, "++")) {
      fprintf(toc, "plusplus(&dataStack);\n");
    }

    else if (!strcmp(cmd, "**")) {
      fprintf(toc, "mulmul(&dataStack);\n");
    }

    else if (!strcmp(cmd, ".")) {
      fprintf(toc, "showtop(&dataStack);\n");
    }

    else if (!strcmp(cmd, "*")) {
      fprintf(toc, "mul(&dataStack);\n");
    }

    else if (!strcmp(cmd, "dels")) {
      fprintf(toc, "delstack(&dataStack);\n");
    }

    else if (!strcmp(cmd, "show")) {
      fprintf(toc, "show(&dataStack);\n");
    }

    else if (!strcmp(cmd, "-")) {
      fprintf(toc, "sub(&dataStack);\n");
    }

    else if (!strcmp(cmd, "swap")) {
      fprintf(toc, "swap(&dataStack);\n");
    }

    else if (!strcmp(cmd, "dup")) {
      fprintf(toc, "duplicate(&dataStack, 0);\n");
    }

    else if(!strcmp(cmd, "jump")) {
      fprintf(toc, "jump(&dataStack);\n");
    }

    else if (!strcmp(cmd, "range")) {
      fprintf(toc, "range(&dataStack);\n");
    }

    else if (!strcmp(cmd, "drop") || !strcmp(cmd, "pop")) {
      fprintf(toc, "drop(&dataStack, true);\n");
    }

    else if (!strcmp(cmd, "over")) {
      fprintf(toc, "duplicate(&dataStack, 1);\n");
    }

    else if (!strcmp(cmd, "wover")) {
      fprintf(toc, "duplicate(&dataStack, 2);\n");
    }

    else if (!strcmp(cmd, "top")) {
      fprintf(toc, "StackPush(&dataStack, dataStack->top);\n");
    }

    else if (!strcmp(cmd, "outascii")) {
      fprintf(toc, "outascii(&charStack);\n");
    }

    else if (!strcmp(cmd, "print")) {
      fprintf(toc, "allascii(&charStack);\n");
    }

    else if (!strcmp(cmd, "/")) {
      fprintf(toc, "divide(&dataStack);");
    }

    //Prints total commands. Used with @tracker
    else if (!strcmp(cmd,"tot")) {
      fprintf(toc, "printf(\"tot: %d\n\");\n", cmds);
    }

    //Resets number of commands. Used with @tracker
    else if (!strcmp(cmd, "reset")) {
      fprintf(toc, "cmds = 0;\n");
    }

    //Starting a loop. Interpreted as a word. Saves the index and control, starts saving words to evaluate later.
    else if (!strcmp(cmd, "[")) {
      if (dataStack->top < 1) {
	fprintf(toc, "error(\"not enough frames!\");\n");
      }
      else {
	fprintf(toc, "loopStack->index = (int) StackPop(&dataStack);\nloopStack->control = (int) StackPop(&dataStack) + 1;\n");
      }
      fprintf(toc, "loopStack->save = true;\n");
    }

    //Pushes the index to the dataStack.
    else if (!strcmp(cmd, "i")) {
      fprintf(toc, "StackPush(&dataStack, loopStack->index);");
    }

    //Increments the index, iterates over the commands if the index < control, otherwise resets the loopStack, and stops saving words.
    else if (strcmp(cmd, "]") == 0) {
      fprintf(toc, "loopStack->index += 1;\n");
      //printf("ind %d\ncon %d\n", loopStack->index, loopStack->control);
      if (loopStack->index <= loopStack->control) {
	for (c = 0; c < loopStack->bufsize; c++) {
	  //printf("%s\n", loopStack->buffer[c]);
	  eval(dataStack, loopStack, list, loopStack->buffer[(int) c], toc, cons);
	}
      }
      else {
	fprintf(toc, "loopStack->index = 0;\nloopStack->control = 0;\nmemset(loopStack->buffer, '\\0', sizeof(loopStack->buffer) * RES_SIZE * DIM2);\nloopStack->bufsize = 0;\nloopStack->save = false;\n");
      }
    }

    //If the command is unrecognized and not a mode setting.
    else {
      if ((cmd[0] != '@') && (cmd[0] != '#')) {
	fprintf(toc, "sprintf(msg, \"%s - unknown command!\");\n", cmd);
	fprintf(toc, "error(msg);\n");
      }
    }

    //If in a loop, saves words. LOOK OUT. EVALUATES THE WORDS IN AN ENDLESS RECURSION. SAVES/EVALUATES THEN ADDS IT TO THE BUFFER. FIX!
    if (loopStack->save && strcmp(cmd, "[")) {
      fprintf(toc, "*loopStack->buffer[loopStack->bufsize++] = *cmd;\n");
    }
  }

  //If not setting the mode, do whatever it is the modes do at the end of the eval() process.
  if (cmd[0] != '@') {
    if (is_enabled(list, "@transparent") && strcmp(cmd, "show") && strcmp(cmd, "tot") && strcmp(cmd, "reset")  && strcmp(cmd, ".") && strcmp(cmd, "dels") && strcmp(cmd, "nil")) {
      fprintf(toc, "printf(\"%s | \");", cmd);
      fprintf(toc, "StackShow(&dataStack);\n");
    }
    if (is_enabled(list, "@tracker") && strcmp(cmd, "tot") && strcmp(cmd, "reset")) {
      fprintf(toc, "cmds++;\n");
    }
    if (!is_enabled(list, "@tracker") && (cmds != 0)) {
      fprintf(toc, "cmds = 0;\n");
    }
  }
}

//REPL
int main(int argc, char *argv[]) {
  FILE *fp;
  FILE *toc;

  //Initializing dataStack
  stackT dataStack;

  //Initializing loop stack
  loopstack loopStack;

  //Initializing modes list
#include "structdef.h"
  loopStack.bufsize = 0;
  loopStack.save = false;

  StackInit(&dataStack, RES_SIZE);
  char cmd[DIM2] = "00";
  char filepath[100];
  cmds = 0;
  if (argc > 1) {
    if (str_in_arr(argc, argv, "-v") || str_in_arr(argc, argv, "--version")) {
      printf("%s %.1f on %s\n", PKGNAME, VERSION, OPSYS);
      exit(1);
    }
    fp = fopen(argv[1], "r");
    sprintf(filepath, "%s.c", argv[1]);
    toc = fopen(filepath, "w+");
    fprintf(toc, "#include <gecho/header.h>\n");
    if (fp != NULL) {
      while (fscanf(fp, "%s", cmd) != EOF) {
	eval(&dataStack, &loopStack, list, cmd, toc, cons);
      }
      fclose(fp);
      fprintf(toc, "}");
      fclose(toc);
    }
    else {
      printf("error: %s - no such file!\n", argv[1]);
      exit(1);
    }
  }
  return 0;
}
