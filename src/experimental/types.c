#include <stdio.h>
#include <ctype.h>

int main() {
	int a = 5;
	int b = typeof(a);
	printf("%i", b);
}
