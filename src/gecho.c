double a, b, c, ind, con;
#define MODETOP 3
#define PKGNAME "gecho"
#define VERSION 0.2
#include "functions.h"
int cmds;
//This is the eval function.
int eval(stackT *dataStack, loopstack *loopStack, mode list[MODETOP], char cmd[]) {
	//Holds an error message.
	char msg[30];
	//printf("cmd: %s\n", cmd);
	//Checks if the first digit is a number, and if so, pushes it.
	if ((cmd[0] >= '0') && (cmd[0] <= '9')) {
		StackPush(dataStack, atof(cmd));
	}
	else {
		//Converts the command to all lowercase.
		for(c = 0; c < strlen(cmd); c++) {
			cmd[(int) c] = tolower(cmd[(int) c]);
		}

		//If it's a mode change...toggle it.
		if ((cmd[0] == '@') && (strlen(cmd) > 1)) {
			a = toggle(list, lookup(list, cmd));
			if (a) {
				printf("--%s %s--\n", cmd, is_enabled(list, cmd)?"ON":"OFF");
			}
		}

		//If the user wants to see the modes enabled.
		else if (!strcmp(cmd, "mode")) {
			for (a = 0; a < MODETOP; a++) {
				if (list[(int) a].enabled) {
					printf("%s   ", list[(int) a].mode);
				}
			}
			printf("\n");
		}

		//If the user wants to see all the modes, complete with if they are enabled.
		else if (!strcmp(cmd, "modes")) {
			for (a = 0; a < MODETOP; a++) {
				printf("%s:%d   ", list[(int) a].mode, is_enabled(list, list[(int) a].mode));
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

		else if (!strcmp(cmd, "drop") || !strcmp(cmd, "pop")) {
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

		//Prints total commands. Used with @tracker
		else if (!strcmp(cmd,"tot")) {
			printf("tot: %d\n", cmds);
		}

		//Resets number of commands. Used with @tracker
		else if (!strcmp(cmd, "reset")) {
			cmds = 0;
		}

		//Starting a loop. Interpreted as a word. Saves the index and control, starts saving words to evaluate later.
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

		//Pushes the index to the dataStack.
		else if (!strcmp(cmd, "i")) {
			StackPush(dataStack, loopStack->index);
		}

		//Increments the index, iterates over the commands if the index < control, otherwise resets the loopStack, and stops saving words.
		else if (strcmp(cmd, "]") == 0) {
			loopStack->index += 1;
			//printf("ind %d\ncon %d\n", loopStack->index, loopStack->control);
			if (loopStack->index <= loopStack->control) {
				for (c = 0; c < loopStack->bufsize; c++) {
					//printf("%s\n", loopStack->buffer[c]);
					eval(dataStack, loopStack, list, loopStack->buffer[(int) c]);
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

		//If the command is unrecognized and not a mode setting.
		else {
			if (cmd[0] != '@') {
				sprintf(msg, "%s - unknown command!", cmd);
				error(msg);
			}
		}

		//If in a loop, saves words. LOOK OUT. EVALUATES THE WORDS IN AN ENDLESS RECURSION. SAVES/EVALUATES THEN ADDS IT TO THE BUFFER. FIX!
		if (loopStack->save && strcmp(cmd, "[")) {
			*loopStack->buffer[loopStack->bufsize++] = *cmd;
		}
	}

	//If not setting the mode, do whatever it is the modes do at the end of the eval() process.
	if (cmd[0] != '@') {
		if (is_enabled(list, "@transparent") && strcmp(cmd, "show") && strcmp(cmd, "tot") && strcmp(cmd, "reset")) {
			printf("%s | ", cmd);
			StackShow(dataStack);
		}
		if (is_enabled(list, "@tracker") && strcmp(cmd, "tot") && strcmp(cmd, "reset")) {
			cmds++;
		}
		if (!is_enabled(list, "@tracker") && (cmds != 0)) {
			cmds = 0;
		}
	}
}

//REPL
int main() {
	printf("%s %.1f on %s\n\n", PKGNAME, VERSION, OPSYS);

	//Initializing dataStack
	stackT dataStack;

	//Initializing loop stack
	loopstack loopStack;

	//Initializing modes list
	mode list[] = {
		{"@default", true},
		{"@transparent", false},
		{"@tracker", false},
	};
	loopStack.bufsize = 0;
	loopStack.save = false;
	//Variables. Will implement with a & prefix to access and a ! prefix to store.
	//TableInit();
	//int top = 0;
	StackInit(&dataStack, RES_SIZE);
	char cmd[DIM2];
	cmds = 0;
	while(1) {
		scanf("%s", cmd);
		if (!strcmp(cmd, "quit") || !strcmp(cmd, "exit")) {
			printf("\nbye\n");
			break;
		}
		eval(&dataStack, &loopStack, list, cmd);
	}
}
