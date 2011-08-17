#define PKGNAME "gecho"
#define VERSION 0.2
#if defined _WIN32 || defined _WIN64
#define OPSYS "Windows"
#endif

#ifdef __unix__
#define OPSYS "Unix"
#endif

#ifdef __APPLE__
#define OPSYS "Mac OS X"
#endif

#ifndef OPSYS
#define OPSYS "unsupported system"
#endif

int a, b, c, ind, con;
#include "functions.h"

int eval(stackT *dataStack, loopstack *loopStack, mode list[MODETOP], char cmd[]) {
	char msg[30];
	//printf("cmd: %s\n", cmd);
	if ((cmd[0] >= '0') && (cmd[0] <= '9')) {
		StackPush(dataStack, atoi(cmd));
	}
	else {
		for(c = 0; c < strlen(cmd); c++) {
			cmd[c] = tolower(cmd[c]);
		}
		if ((cmd[0] == '@') && (strlen(cmd) > 1)) {
			for (a = 0; a < strlen(cmd); a++) {
				a = toggle(list, lookup(list, cmd));
			}
			if (a) {
				printf("--MODE %s--\n", cmd);
			}
		}
		else if (!strcmp(cmd, "mode")) {
			for (a = 0; a < MODETOP; a++) {
				if (list[a].enabled) {
					printf("%s   ", list[a].mode);
				}
			}
			printf("\n");
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
					eval(dataStack, loopStack, list, loopStack->buffer[c]);
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
		if (loopStack->save && strcmp(cmd, "[")) {
			*loopStack->buffer[loopStack->bufsize++] = *cmd;
		}
	}
	if (cmd[0] != '@') {
		if (is_enabled(list, "@transparent") && strcmp(cmd, "show")) {
			printf("%s | ", cmd);
			StackShow(dataStack);
		}
		else if (is_enabled(list,"@separate")) {
			printf("--------------------\n");
		}
	}
}

int main() {
	printf("%s %.1f on %s\n\n", PKGNAME, VERSION, OPSYS);
	stackT dataStack;
	loopstack loopStack;
	mode list[] = {
		{"@default", true},
		{"@default", false},
		{"@separate", false},
	};
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
		eval(&dataStack, &loopStack, list, cmd);
	}
}
