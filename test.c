#include <stdio.h>

double f(double x) {
	if (x < 1) return 1;
	else return x*f(x-1);
}

int main() {
	printf("%f\n", f(20));
}
