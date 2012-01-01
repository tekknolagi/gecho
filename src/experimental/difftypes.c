#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  INT(x) *((int*)x)
#define  STR(x) (char*)x

void pprint(void *arr, int len) {
	//iterate over
	//check type
	//print accordingly
	//exit
}

int main(int argc, char **argv) {
	void *a[2];

	if (argc <= 1) {
	  char b[] = "hello";
	  a[1] = calloc(strlen(b), sizeof(char));
	  a[1] = strncpy(a[1], b, strlen(b));
	}
	else {
	  a[1] = calloc(strlen(argv[1]), sizeof(char));
	  a[1] = strncpy(a[1], argv[1], strlen(argv[1]));
	}

	a[0] = calloc(1, sizeof(int));
	INT(a[0]) = strlen(a[1]);

	printf("%d\n", INT(a[0]));
	printf("%s\n", STR(a[1]));
	free(a[1]);
	free(a[0]);
	return 0;
}
