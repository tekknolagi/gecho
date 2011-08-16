#define PKGNAME "gecho"
#define VERSION 0.2

int a, b, c, ind, con;
#include "functions.h"


int eval(stackT *dataStack, loopstack *loopStack, global_vars *globals, char cmd[]) {
	char msg[30];
	//printf("cmd: %s\n", cmd);
	//printf("mode: %s\n", globals->mode);
	//printf("cmd[0]: %c\n", cmd[0]);
	if ((cmd[0] >= '0') && (cmd[0] <= '9')) {
		StackPush(dataStack, atoi(cmd));
	}
	else {
		for(c = 0; c < strlen(cmd); c++) {
			cmd[c] = tolower(cmd[c]);
		}
		if ((cmd[0] == '@') && (strlen(cmd) > 1)) {
			//mode = cmd;
			printf("--MODE %s--\n", cmd);
			for (a = 0; a < strlen(cmd)-1; a++) {
				globals->mode[a] = cmd[a];
			}
			//printf("mode: %s\n", dataStack->mode);
		}
		else if (!strcmp(cmd, "mode")) {
			printf("mode: %s\n", globals->mode);
}
		else if (!strcmp(cmd, "+")) {
			plus(dataStack);
		}

		else if (!strcmp(cmd, "++")) {
			plusplus(dataStack);
		}

		else if (!strcmp(cmd, "**")) {
			mulmul(dataStack);
		}

		else if (!strcmp(cmd, ".")) {
			showtop(dataStack);
		}

		else if (!strcmp(cmd, "*")) {
			mul(dataStack);
		}

		else if (!strcmp(cmd, "..")) {
			delstack(dataStack);
		}

		else if (!strcmp(cmd, "show")) {
			show(dataStack);
		}

		else if (!strcmp(cmd, "-")) {
			sub(dataStack);
		}

		else if (!strcmp(cmd, "swap")) {
			swap(dataStack);
		}

		else if (!strcmp(cmd, "dup")) {
			duplicate(dataStack, 0);
		}

		else if(!strcmp(cmd, "jump")) {
			jump(dataStack);
		}

		else if (!strcmp(cmd, "range")) {
			range(dataStack);
		}

		else if (!strcmp(cmd, "drop")) {
			drop(dataStack, true);
		}

		else if (!strcmp(cmd, "over")) {
			duplicate(dataStack, 1);
		}

		else if (!strcmp(cmd, "wover")) {
			duplicate(dataStack, 2);
		}

		else if (!strcmp(cmd, "top")) {
			StackPush(dataStack, dataStack->top);
		}

		else if (!strcmp(cmd, "outascii")) {
			outascii(dataStack);
		}

		else if (!strcmp(cmd, "allascii")) {
			allascii(dataStack);
		}

		else if (!strcmp(cmd, "/")) {
			divide(dataStack);
		}

		else if (!strcmp(cmd, "[")) {
			if (dataStack->top < 1) {
				error("not enough frames!");
			}
			else {
				loopStack->index = (int) StackPop(dataStack);
				loopStack->control = (int) StackPop(dataStack) + 1;
			}
			loopStack->save = true;
		}

		else if (!strcmp(cmd, "i")) {
			StackPush(dataStack, loopStack->index);
		}

		else if (strcmp(cmd, "]") == 0) {
			loopStack->index += 1;
			//printf("ind %d\ncon %d\n", loopStack->index, loopStack->control);
			if (loopStack->index <= loopStack->control) {
				for (c = 0; c < loopStack->bufsize; c++) {
					//printf("%s\n", loopStack->buffer[c]);
					eval(dataStack, loopStack, globals, loopStack->buffer[c]);
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
			if (cmd[0] != '@') {
				sprintf(msg, "%s - unknown command!", cmd);
				error(msg);
			}
		}
		if (loopStack->save && (strcmp(cmd, "[") != 0)) {
			//printf("cmd: %s\n", cmd);
			//printf("ptr: %d\n", *cmd);
			*loopStack->buffer[loopStack->bufsize++] = *cmd;
		}
		else if (!strcmp(globals->mode, "@transp")) {
			StackShow(dataStack);
		}
		//return top;
	}
}

int main() {
	printf("%s %.1f\n\n", PKGNAME, VERSION);
	stackT dataStack;
	loopstack loopStack;
	global_vars globals;
	loopStack.bufsize = 0;
	loopStack.save = false;
	//TableInit();
	//int top = 0;
	StackInit(&dataStack, RES_SIZE);
	char cmd[DIM2];
	//globals.mode = "@default";
	while(1) {
		//printf("s>   ");
		scanf("%s", cmd);
		eval(&dataStack, &loopStack, &globals, cmd);
	}
}
