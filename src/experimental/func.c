#include <stdio.h>

void foobar() {
  printf("sex\n");
}

void arr(void (*foo)()) {
  (* foo)();
}

int main() {
  arr(foobar);
}
