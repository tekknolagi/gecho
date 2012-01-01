#ifndef USEFUNC_H
#define USEFUNC_H

#include <stdio.h>
//#include <gmp.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <unistd.h>
#include <iso646.h>
#define YELLOW  "\e[1;33m"
#define PURPLE  "\e[1;35m"
#define BLUE    "\e[1;34m"
#define RED     "\e[1;31m"
#define DEFAULT "\e[0m"

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028
#endif

#ifndef M_PHI
#define M_PHI 1.618033988749894848204586834365638
#endif

#ifndef M_E
#define M_E 2.71828182845904523536028747135266249
#endif

#define DIM2 30
#define RES_SIZE 100000
#define VAR_SIZE 100
#define NUM_STACKS 5

#define MODETOP 3
#define CONSTOP 7

#ifdef __unix__
#define OPSYS "Unix"
#endif

#ifdef __APPLE__
#define OPSYS "Mac OS X"
#endif

#ifndef OPSYS
#define OPSYS "unsupported system"
#endif

#endif
