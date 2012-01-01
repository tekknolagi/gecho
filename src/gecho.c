double a, b, c, ind, con;

int var_index;
#define PKGNAME "gecho [expanded]"
#define VERSION 0.6
#include "functions.h"
int cmds;
int top;
double variables[RES_SIZE];
stackT charStack;
char *WORD;

void next() {
	if (which < NUM_STACKS-1) which++;
	else which = 0;
}

void back() {
	if (which >= 1) which--;
	else which = NUM_STACKS-1;
}

//This is the eval function.
void eval(stackT dataStack[], loopstack *loopStack, mode list[MODETOP], char cmd[], const_list cons[CONSTOP]) {
	//Holds an error message.
	char msg[30];
	//Checks if the first digit is a number, and if so, pushes it.	
	if ((cmd[0] == '-') && (isdigit(cmd[1]) || cmd[1] == '.')) {
		StackPush(&dataStack[which], atof(cmd));
	}
	else if (isdigit(cmd[0]) || ((cmd[0] == '.') && isdigit(cmd[1]))) {
		StackPush(&dataStack[which], atof(cmd));
	}
	else if (!strcmp(cmd, "<>")) {
		StackPush(&charStack, (int) ' ');
	}
	else if ((cmd[0] == '\'') || (cmd[0] == '`')) {
		if (strlen(cmd) > 1) {
			for (a = 1; a < strlen(cmd); a++) {
				StackPush(&charStack, (int) cmd[(int) a]);
			}
		}
		else {
			error("not a valid char/string!");
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
				printf(BLUE "--%s %s--\n" DEFAULT, cmd, is_enabled(list, cmd)?"ON":"OFF");
			}
		}

		else if (cmd[0] == '#') {
			if (strlen(cmd) > 1) {
				if (c_lookup(cons, cmd) != -1) {
					StackPush(&dataStack[which], cons[c_lookup(cons, cmd)].value);
				}
			}
			else {
				error("not enough frames!");
			}
		}

		else if (!strcmp(cmd, "and")) {
			log_and(&dataStack[which]);
		}

		else if (!strcmp(cmd, "or")) {
			log_or(&dataStack[which]);
		}
		
		else if ((cmd[0] == '!') && (strlen(cmd) > 1) && (cmd[1] >= '-') && (cmd[1] <= '9')) {
			var_index = atoi(cmd+1);
			if (&dataStack[which].top >= 0) {
				variables[var_index] = StackPop(&dataStack[which]);
			}
			else {
				error("stack is empty!");
			}
		}

		else if (!strcmp(cmd, "pow")) {
			powers(&dataStack[which]);
		}

		else if (!strcmp(cmd, "mod")) {
			modulus(&dataStack[which]);
		}

		else if (!strcmp(cmd, "tan")) {
			tangent(&dataStack[which]);
		}

		else if (!strcmp(cmd, "sin")) {
			sine(&dataStack[which]);
		}

		else if (!strcmp(cmd, "cos")) {
			cosine(&dataStack[which]);
		}

		else if (!strcmp(cmd, "read")) {
			userin(&dataStack[which]);
		}

		else if (!strcmp(cmd, ">")) {
			gt(&dataStack[which]);
		}

		else if (!strcmp(cmd, "<")) {
			lt(&dataStack[which]);
		}

		else if (!strcmp(cmd, "=")) {
			eqeq(&dataStack[which]);
		}

		else if (!strcmp(cmd, "<=")) {
			lteq(&dataStack[which]);
		}

		else if (!strcmp(cmd, ">=")) {
			gteq(&dataStack[which]);
		}

		else if ((cmd[0] == '&') && (strlen(cmd) > 1) && (cmd[1] >= '-') && (cmd[1] <= '9')) {
			var_index = atoi(cmd+1);
			StackPush(&dataStack[which], variables[var_index]);
		}

		//If the user wants to see the modes enabled.
		else if (!strcmp(cmd, "mode")) {
			for (a = 0; a < MODETOP; a++) {
				if (list[(int) a].enabled) {
					printf(BLUE "%s   " DEFAULT, list[(int) a].mode);
				}
			}
			printf("\n");
		}

		//If the user wants to see all the modes, complete with if they are enabled.
		else if (!strcmp(cmd, "modes")) {
			for (a = 0; a < MODETOP; a++) {
				printf(BLUE "%s" DEFAULT ":" PURPLE "%d   " DEFAULT, list[(int) a].mode, is_enabled(list, list[(int) a].mode));
			}
			printf("\n");
		}

		else if (!strcmp(cmd, "+")) {
			plus(&dataStack[which]);
		}

		else if (!strcmp(cmd, "++")) {
			plusplus(&dataStack[which]);
		}

		else if (!strcmp(cmd, "**")) {
			mulmul(&dataStack[which]);
		}

		else if (!strcmp(cmd, ".")) {
			showtop(&dataStack[which]);
		}

		else if (!strcmp(cmd, "*")) {
			mul(&dataStack[which]);
		}

		else if (!strcmp(cmd, "dels")) {
			delstack(&dataStack[which]);
		}

		else if (!strcmp(cmd, "show")) {
			StackShow(&dataStack[which]);
		}

		else if (!strcmp(cmd, "-")) {
			sub(&dataStack[which]);
		}

		else if (!strcmp(cmd, "swap")) {
			swap(&dataStack[which]);
		}

		else if (!strcmp(cmd, "dup")) {
			duplicate(&dataStack[which], 0);
		}

		else if(!strcmp(cmd, "jump")) {
			jump(&dataStack[which]);
		}

		else if (!strcmp(cmd, "range")) {
			range(&dataStack[which]);
		}

		else if (!strcmp(cmd, "drop") || !strcmp(cmd, "pop")) {
			drop(&dataStack[which], true);
		}

		else if (!strcmp(cmd, "over")) {
			duplicate(&dataStack[which], 1);
		}

		else if (!strcmp(cmd, "wover")) {
			duplicate(&dataStack[which], 2);
		}

		else if (!strcmp(cmd, "top")) {
			StackPush(&dataStack[which], dataStack[which].top);
		}

		else if (!strcmp(cmd, "next")) {
			next();
		}

		else if (!strcmp(cmd, "back")) {
			back();
		}

		else if (!strcmp(cmd, "outascii")) {
			outascii(&charStack);
		}

		else if (!strcmp(cmd, "print")) {
			allascii(&charStack);
		}

		else if (!strcmp(cmd, "mv")) {
			a = StackPop(&dataStack[which]);
			next();
			StackPush(&dataStack[which], a);
		}

		else if (!strcmp(cmd, "/")) {
			divide(&dataStack[which]);
		}

		else if (cmd[0] == '{') {
			printf("return val: %d\n", sscanf(cmd, "{%s}", WORD));
			printf("body: %s\n", WORD);
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
			if (dataStack[which].top < 1) {
				error("not enough frames!");
			}
			else {
				loopStack->index = (int) StackPop(&dataStack[which]);
				loopStack->control = (int) StackPop(&dataStack[which]) + 1;
			}
			loopStack->save = true;
		}

		//Pushes the index to the dataStack.
		else if (!strcmp(cmd, "i")) {
			StackPush(&dataStack[which], loopStack->index);
		}

		//Increments the index, iterates over the commands if the index < control, otherwise resets the loopStack, and stops saving words.
		else if (strcmp(cmd, "]") == 0) {
			loopStack->index += 1;
			//printf("ind %d\ncon %d\n", loopStack->index, loopStack->control);
			if (loopStack->index <= loopStack->control) {
				for (c = 0; c < loopStack->bufsize; c++) {
					//printf("%s\n", loopStack->buffer[c]);
					//FIX LAME EVAL
					eval(&dataStack[which], loopStack, list, loopStack->buffer[(int) c], cons);
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

		//If the command is unrecognized and not a mode setting or constant.
		else {
			if ((cmd[0] != '@') && (cmd[0] != '#')) {
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
		if (is_enabled(list, "@transparent") && strcmp(cmd, "show") && strcmp(cmd, "tot") && strcmp(cmd, "reset") && strcmp(cmd, ".") && strcmp(cmd, "dels") && strcmp(cmd, "nil")) {
			printf("%s | ", cmd);
			StackShow(&dataStack[which]);
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
int main(int argc, char *argv[]) {
	flags flagl;
	FILE *fp;

	which = 0;

	//Initializing dataStack
	stackT dataStack[NUM_STACKS];

	//Initializing loop stack
	loopstack loopStack;

	//Initializing modes&&const list
#include "structdef.h"

	flagl.version = 0;
	flagl.eval = 0;
	flagl.shell = 0;
	flagl.f = 0;
	flagl.help = 0;
	flagl.fn = NULL;
	int index;
	int optt;
	opterr = 0;

	while ((optt = getopt(argc, argv, "hvesf:")) != -1) {
		switch(optt) {
		case 'h':
			flagl.version = 1;
			flagl.help = 1;
			break;
		case 'v':
			flagl.version = 1;
			break;
		case 'e':
			flagl.eval = 1;
			break;
		case 'f':
			flagl.f = 1;
			flagl.fn = optarg;
			break;
		case 's':
			flagl.shell = 1;
			break;
		case '?':
			if (optopt == 'f')
				printf("Option `-%c\' requires argument!\n", optopt);
			else if (isprint(optopt))
				printf("Unknown option `-%c\'.\n", optopt);
			else
				printf("Unknown option character `\\x%x\'.\n", optopt);
			return 1;
		default:
			abort();
		}
	}

	for (index = optind; index < argc; index++) {
		printf("Non-option argument %s\n", argv[index]);
	}
	
	if (flagl.help) {
	    printf("Usage:\ngecho -[h v e f s]\n where -f has one argument; a file\nand -v prints the version\nand -e evaluates the string passed to gecho\nand -s goes into a shell after evaluating a file\n and -h brings up this screen.");
	}

	loopStack.bufsize = 0;
	loopStack.save = false;
  
	for (a = 0; a < NUM_STACKS; a++)
		StackInit(&dataStack[(int) a], RES_SIZE);

	StackInit(&charStack, RES_SIZE);
	char cmd[DIM2] = "00";
	cmds = 0;
	if (argc > 1) {
		if (flagl.version) {
			printf("%s %.1f on %s\n", PKGNAME, VERSION, OPSYS);
			exit(1);
		}
		if (!flagl.eval && flagl.f) {
			fp = fopen(flagl.fn, "r");
			if (fp != NULL) {
				while (fscanf(fp, "%s", cmd) != EOF) {
					eval(dataStack, &loopStack, list, cmd, cons);
				}
				fclose(fp);
				if (!flagl.shell) {
					exit(1);
				}
				printf("~~~~~~~~~~\n");
			}
			else {
				printf("error: %s - no such file!\n", flagl.fn);
				exit(1);
			}
		}
	}

	if (!flagl.eval && !flagl.shell) {
		printf("%s %.1f on %s\n\n", PKGNAME, VERSION, OPSYS);
	}

	while(1) {
		scanf("%s", cmd);
		if (!strcmp(cmd, "quit") || !strcmp(cmd, "exit")) {
			if (!flagl.eval) {
				printf("\nbye\n");
			}
			break;
		}
		eval(dataStack, &loopStack, list, cmd, cons);
	}
	return 0;
}
