#include "stack.h"

bool str_in_arr(int argc, char *argv[], char *match) {
	int i;
	for (i = 0; i < argc; i++)
		if (!strcmp(match, argv[i]))
			return 1;
	return 0;
}

bool char_in_arr(char tosearch, char arr[]) {
	int i = 0;
	for(; i < strlen(arr); i++) {
		if (arr[i] == tosearch) {
			return true;
		}
	}
	return false;
}

//Easier error management.
void error(char* msg) {
	printf("error: %s\n", msg);
}

//Easier return management.
void ret(double msg) {
	printf(">  %.2f\n", msg);
}

//Adds two numbers. If only one is on the stack, adds 0 to it.
void plus(stackT *dataStack) {
	if (dataStack->top < 1) {
		StackPush(dataStack, 0);
		plus(dataStack);
	}
	else {
		b = StackPop(dataStack);
		a = StackPop(dataStack);
		StackPush(dataStack, a+b);
	}
}

//Adds all the numbers on the stack. If only one is on the stack, pushes a 0.
void plusplus(stackT *dataStack) {
	if (dataStack->top < 1) {
		StackPush(dataStack, 0);
		plus(dataStack);
	}
	else {
		while (dataStack->top >= 1) {
			plus(dataStack);
		}
	}
}

//Multiplies two numbers. If only one is on the stack, multiplies it by 1.
void mul(stackT *dataStack) {
	if (dataStack->top < 1) {
		StackPush(dataStack, 1);
		mul(dataStack);
	}
	else {
		b = StackPop(dataStack);
		a = StackPop(dataStack);
		StackPush(dataStack, a*b);
		//printf("%.0f * %.0f\n", a, b);
	}
}

//Multiplies all the numbers on the stack. If only one is on the stack, multiplies it by 1.
void mulmul(stackT *dataStack) {
	if (dataStack->top < 1) {
		StackPush(dataStack, 1);
		mulmul(dataStack);
	}
	else {
		while (dataStack->top >= 1) {
			mul(dataStack);
		}
	}
}

//Prints the top number on the stack or outputs an error if there are no numbers on the stack.
void showtop(stackT *dataStack) {
	if (StackIsEmpty(dataStack)) {
		error("stack is empty!");
	}
	else {
		ret(dataStack->contents[dataStack->top]);
	}
}

//Pops the top number off the stack, or outputs an error if there are no numbers on the stack.
void drop(stackT *dataStack, bool show) {
	if (StackIsEmpty(dataStack)) {
		error("stack is empty!");
	}
	else {
		if(show) {
			ret(StackPop(dataStack));
		}
		else {
			StackPop(dataStack);
		}
	}
}

//Pops all numbers off the stack.
void delstack(stackT *dataStack) {
	if (!StackIsEmpty(dataStack)) {
		while (dataStack->top > -1) {
			drop(dataStack, false);
		}
	}
}

//Pretty-prints the stack.
void show(stackT *dataStack) {
	printf(">  ");
	StackShow(dataStack);
}

//Subtracts the top two numbers on the stack, or pushes 0 onto the stack and subtracts 0 from the number.
void sub(stackT *dataStack) {
	if (dataStack->top < 1) {
		StackPush(dataStack, 0);
		sub(dataStack);
	}
	else {
		b = StackPop(dataStack);
		a = StackPop(dataStack);
		StackPush(dataStack, a-b);
	}
}

//Swaps the places of the top two numbers on the stack.
void swap(stackT *dataStack) {
	if (dataStack->top < 1) {
		error("not enough frames!");
	}
	else {
		b = StackPop(dataStack);
		a = StackPop(dataStack);
		StackPush(dataStack, b);
		StackPush(dataStack, a);
	}
}

//Pushes a copy of the top number onto the stack.
void duplicate(stackT *dataStack, int num) {
	if (dataStack->top < num) {
		error("stack is empty!");
	}
	else {
		StackPush(dataStack, dataStack->contents[dataStack->top - num]);
	}
}

//Prints the number at the index of the top number on the stack.
void jump(stackT *dataStack) {
	if (StackIsEmpty(dataStack)) {
		error("stack is empty!");
	}
	else {
		a = StackPop(dataStack)+1;
		if (a > dataStack->top) {
			error("not enough frames!");
		}
		else {
			ret(dataStack->contents[(int) a]);
		}
	}
}

//Pushes a range of numbers to the stack in the order they are specified. If the stack is [ 0, 5 ] it will push [ 0,1, 2, 3, 4, 5 ]. If the stack is [ 5, 0] it will push [5, 4, 3, 2, 1, 0 ].
void range(stackT *dataStack) {
	if (dataStack->top < 1) {
		error("not enough frames!");
	}
	else {
		b = StackPop(dataStack);
		a = StackPop(dataStack);
		if (a < b) {
			for (c = a; c <= b; c++) {
				StackPush(dataStack, c);
			}
		}
		else if (a > b) {
			for (c = a; c >= b; c--) {
				StackPush(dataStack, c);
			}
		}
		else if (a == b) {
			StackPush(dataStack, a);
		}
	}
}

//Outputs the ASCII representation of the top number on the stack.
void outascii(stackT *dataStack) {
	if (dataStack->top < 0) {
		error("not enough frames!");
	}
	else {
		printf(">  %c\n", (unsigned char) StackPop(dataStack));
	}
}

//Outputs all the numbers on the stack as ASCII in the order they appear. [ 87, 98, 99 ] will result in "abc".
void allascii(stackT *dataStack) {
	if (dataStack->top < 0) {
		error("not enough frames!");
	}
	else {
		printf(">  ");
		for (a = 0; a < dataStack->top+1; a++) {
			printf("%c", (unsigned char) dataStack->contents[(int) a]);
		}
		printf("\n");
		delstack(dataStack);
	}
}

//Divides the top two numbers on the stack.
void divide(stackT *dataStack) {
	if (dataStack->top < 1) {
		error("not enough frames!");
	}
	else {
		b = StackPop(dataStack);
		a = StackPop(dataStack);
		StackPush(dataStack, a/b);
	}
}

//Toggles a mode on/off.
int toggle(mode *list, int index) {
	if (index < 0) {
		error("toggle error: no such mode!");
		return 0;
	}
	else {
		list[index].enabled = !(list[index].enabled);
		return 1;
	}
}

//Finds the index of a particular mode.
int lookup(mode *list, char *mode) {
	for (a = 0; a < MODETOP; a++) {
		if (!strcmp(list[ (int) a].mode, mode)) {
			return (int) a;
		}
	}
	return -1;
}

//Checks whether a mode is enabled or not.
int is_enabled(mode *list, char *mode) {
	a = lookup(list, mode);
	if (a < 0) {
		printf("error: is_enabled error: %s -  no such mode!", mode);
		return 0;
	}
	return list[lookup(list, mode)].enabled; 
}

void powers(stackT *dataStack) {
	if (dataStack->top < 1) {
		StackPush(dataStack, 1.0);
		powers(dataStack);
	}
	else {
		b = StackPop(dataStack);
		a = StackPop(dataStack);
		StackPush(dataStack, pow(a, b));
	}
}

void modulus(stackT *dataStack) {
	if (dataStack->top  < 1) {
		StackPush(dataStack, 1.0);
		modulus(dataStack);
	}
	else {
		b = StackPop(dataStack);
		a = StackPop(dataStack);
		StackPush(dataStack, (int) a % (int)b);
	}
}

double deg2rad(double degrees) {
	return (M_PI/180)*degrees;
}

double rad2deg(double radians) {
	return (180/M_PI)*radians;
}

void tangent(stackT *dataStack) {
	if (dataStack->top < 0) {
		error("stack is empty!");
	}
	else {
		StackPush(dataStack, tan(deg2rad(StackPop(dataStack))));
	}
}

void sine(stackT *dataStack) {
	if (dataStack->top < 0) {
		error("stack is empty!");
	}
	else {
		StackPush(dataStack, sin(deg2rad(StackPop(dataStack))));
	}
}

void cosine(stackT *dataStack) {
	if (dataStack->top < 0) {
		error("stack is empty!");
	}
	else {
		StackPush(dataStack, cos(deg2rad(StackPop(dataStack))));
	}
}
