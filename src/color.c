#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <iso646.h>

#define YELLOW  "\e[1;33m"
#define PURPLE  "\e[1;35m"
#define BLUE    "\e[1;34m"
#define RED     "\e[1;31m"
#define DEFAULT "\e[0m"

int main() {
	printf(YELLOW "he" RED "llo, " BLUE "world" PURPLE "!" DEFAULT "\n");
}
