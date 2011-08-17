#include "stack_imp.h"

void error(char* msg) {
	printf("error: %s\n", msg);
}

void ret(double msg) {
	printf(">  %.2f\n", msg);
}

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

void mul(stackT *dataStack) {
	if (dataStack->top < 1) {
		StackPush(dataStack, 1);
		mul(dataStack);
	}
	else {
		b = StackPop(dataStack);
		a = StackPop(dataStack);
		StackPush(dataStack, a*b);
	}
}

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

void showtop(stackT *dataStack) {
	if (StackIsEmpty(dataStack)) {
		error("stack is empty!");
	}
	else {
		ret(dataStack->contents[dataStack->top]);
	}
}

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

void delstack(stackT *dataStack) {
	if (!StackIsEmpty(dataStack)) {
		while (dataStack->top > -1) {
			drop(dataStack, false);
		}
	}
}

void show(stackT *dataStack) {
	printf(">  ");
	StackShow(dataStack);
}

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

void duplicate(stackT *dataStack, int num) {
	if (dataStack->top < num) {
		error("stack is empty!");
	}
	else {
		StackPush(dataStack, dataStack->contents[dataStack->top - num]);
	}
}

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
			ret(dataStack->contents[a]);
		}
	}
}

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

void outascii(stackT *dataStack) {
	if (dataStack->top < 0) {
		error("not enough frames!");
	}
	else {
		printf(">  %c\n", (unsigned char) StackPop(dataStack));
	}
}

void allascii(stackT *dataStack) {
	if (dataStack->top < 0) {
		error("not enough frames!");
	}
	else {
		printf(">  ");
		for (a = 0; a < dataStack->top+1; a++) {
			printf("%c", (unsigned char) dataStack->contents[a]);
		}
		printf("\n");
		delstack(dataStack);
	}
}

void divide(stackT *dataStack) {
	if (dataStack->top < 1) {
		error("not enough frames!");
	}
	else {
		b = StackPop(dataStack);
		a = StackPop(dataStack);
		StackPush(dataStack, (double) a/b);
	}
}

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

int lookup(mode *list, char *mode) {
	for (a = 0; a < MODETOP; a++) {
		if (!strcmp(list[a].mode, mode)) {
			return a;
		}
	}
	return -1;
}

int is_enabled(mode *list, char *mode) {
	a = lookup(list, mode);
	if (a < 0) {
		error("is_enabled error: no such mode!");
		return 0;
	}
	return list[lookup(list, mode)].enabled; 
}
