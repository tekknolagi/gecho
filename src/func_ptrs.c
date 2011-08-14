#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 5

void hello_func(char name[]) {
	if (strlen(name) > MAXLEN-1) {
		name[MAXLEN-1] = '\0';
	}
	printf("Hello, %s!\n", name);
}

void caps_func(char *word) {
	if ((word[0] >= 'a') && (word[0] <= 'z')) {
		word[0] -= 32;
	}
}

typedef struct {
	void (*hello)(char name[]);
	void (*caps)(char *word);
} myclass;

int main(int argc, char *argv[]) {
	myclass f = {hello_func, caps_func};
	if (argc > 1) {
		int i;
		for (i = 1; i < argc; i++) {
			f.caps(argv[i]);
			f.hello(argv[i]);
		} 
	}
	else {
		printf("Hello, world!\n");
	}
}
