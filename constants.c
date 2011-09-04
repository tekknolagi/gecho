#include <gecho/header.h>
printf("--@transparent ON--\n");
StackPush(dataStack, cons[c_lookup(cons, cmd)].value);
printf("#true | ");StackShow(&dataStack);
StackPush(dataStack, cons[c_lookup(cons, cmd)].value);
printf("#false | ");StackShow(&dataStack);
printf("and | ");StackShow(&dataStack);
showtop(&dataStack);
}