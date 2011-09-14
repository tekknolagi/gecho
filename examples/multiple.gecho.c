#include <gecho/header.h>
printf("--@transparent ON--\n");
StackPush(&dataStack[which], 1.000000);
printf("1 | ");StackShow(&dataStack[which]);
StackPush(&dataStack[which], 2.000000);
printf("2 | ");StackShow(&dataStack[which]);
plus(&dataStack[which]);
printf("+ | ");StackShow(&dataStack[which]);
showtop(&dataStack[which]);
next();
printf("next | ");StackShow(&dataStack[which]);
StackPush(&dataStack[which], 3.000000);
printf("3 | ");StackShow(&dataStack[which]);
StackPush(&dataStack[which], 4.000000);
printf("4 | ");StackShow(&dataStack[which]);
plus(&dataStack[which]);
printf("+ | ");StackShow(&dataStack[which]);
showtop(&dataStack[which]);
back();
printf("back | ");StackShow(&dataStack[which]);
}