#include <stdio.h>
#include <gmp.h>

mpf_t factorial(int x) {
	mpf_t mul_res;
	mpf_init(mul_res);
	if (x < 1) return (mpf_t) 1;
	mpf_mul_ui(mul_res, factorial(x-1), x);
	else return mul_res; 
}

int main() {
	mpf_t a, b;//, b, inter;
	//mpf_init_set_d(a, (double) 5);
	//mpf_init_set_d(b, (double) 5);
	//mpf_init(inter);
	//mpf_add(inter, a, b);
	mpf_init(a);
	mpf_init(b);
	//gmp_printf("%.2Ff+%.2Ff=%.2Ff\n", a, b, inter);
	mpf_set_d(a, (double) 5);
	mpf_set_mpf(b, factorial(a));
	gmp_printf("%.0Ff! = %.0Ff\n", a, b);
}
