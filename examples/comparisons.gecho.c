#include <gecho/header.h>
printf("--@transparent ON--\n");
StackPush(&dataStack, 2.000000);
printf("2 | ");StackShow(&dataStack);
StackPush(&dataStack, 3.000000);
printf("3 | ");StackShow(&dataStack);
lt(&dataStack);
printf("< | ");StackShow(&dataStack);
showtop(&dataStack);
}